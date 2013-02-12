////////////////////
/// Advanced C++
/// Adventure Game 2 
/// Malkov/Danchenkov
////////////////////
#ifndef __DarkFoster_h__
#define __DarkFoster_h__
#include "Room.h"
#include "Enemy.h"
#include <vector>
#include <sstream>
#include <algorithm>  
#include "LurkCommand.h" 
#include <iostream>
#include <random>       
#include <chrono>  

using namespace std;
//////////////////////////////////////
class DarkForest : public Room{
  
private:  
  vector<Enemy> enemyVector;
  Enemy* currentEnemy;
  bool noticedPlayer;
  int numberOfEnemies;

public:
  vector<Enemy> * GetEnemyVector (){
    return & enemyVector;
  }


  DarkForest(){

      //currentEnemy = new Enemy();
      noticedPlayer = false;
      numberOfEnemies = 4; //number of enemies can be changed; you increase it, add also necessary cases.

      SetDescription("You are completely lost, and find yourself out in some very very dark place....");
       
      for (int i = 0; i != numberOfEnemies; i++){
        
            Enemy e;

            switch (i)
            { 
              case 0:
                e.SetName("Dark elf");
                e.SetHitpoints(i+1);
                enemyVector.push_back(e);
                break;

              case 1:
                e.SetName("Angry Dark elf");
                e.SetHitpoints(i+2);
                enemyVector.push_back(e);
                break;

              case 2:
                e.SetName("Dark elf wizard");
                e.SetHitpoints(i+3);
                enemyVector.push_back(e);
                break;

              case 3:
                e.SetName("King of Elves"); // Elves :) 
                e.SetHitpoints(i+4);
                enemyVector.push_back(e);
                break;
            }

          }      

        //* C++11 feature *//
        //* shuffle *//

        //unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        //shuffle (enemyVector.begin(), enemyVector.end(), default_random_engine(seed));
        
        random_shuffle(enemyVector.begin(), enemyVector.end());
        
        currentEnemy = &*enemyVector.begin();
  } 


    //////////////////////////////////////
  // bool brandNewFunction(Enemy enemy){
  //   return enemy.IsAlive();
  // }
  /////////////////////////////////////


  void Update() {

     
     // currentEnemy = enemyVector.begin();

     

    // vector<Enemy>::iterator it = find_if(enemyVector.begin(), enemyVector.end(), brandNewFunction);
        
      if ( currentEnemy->IsAlive() && noticedPlayer )
      { 
          std::ostringstream s;
          Player & player = GetGame()->GetPlayer();
          s << currentEnemy->GetName() << " (" << currentEnemy->GetHitpoints() << "HP)" 
                            << " attacks " << player.GetName() << "\n";
          GetGame()->GetRenderer()->Render(s.str());

          currentEnemy->Attack(&player);
       }

       noticedPlayer = true;
  }

      Room * OnMoveCommand( MoveCommand *pCommand )
      {
        if ( currentEnemy->IsAlive())
        {
           std::ostringstream s;
           s << currentEnemy->GetName() << ": Nice try! But you won't go anywhere!" << "\n";
           GetGame()->GetRenderer()->Render(s.str());
           return NULL;
        }
        else
          return GetNextRoom( pCommand->GetDirection() );
      }
    

      void OnAttack( AttackCommand *pCommand )
      {
        if ( currentEnemy->IsAlive() && noticedPlayer)
        {
          Player & player = GetGame()->GetPlayer();
          std::ostringstream s;
          s << player.GetName() << "(" << player.GetHitpoints() << " HP)" << " attacks " 
                            << currentEnemy->GetName() <<"\n";
          GetGame()->GetRenderer()->Render(s.str());
          player.Attack( currentEnemy );

          // Change room description a bit
          if ( currentEnemy->IsAlive() == false )
          {
             SetDescription("You are in the dark forest. Somethings strange is going on.");
          }
        } 
        else 
        {
          // to encourage player to stop beating it further
          GetGame()->GetRenderer()->Render("Whoa! You already got your pound of flesh out of that one. Literally.\n");
        }

      }

};
////////////////////////////////////////////////////////////////////////////////



#endif
