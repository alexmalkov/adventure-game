////////////////////
/// Advanced C++
/// Adventure Game 2 
/// Malkov/Danchenkov
////////////////////
#ifndef __DarkFoster_h__
#define __DarkFoster_h__
#include "Room.h"
#include "Enemy.h"
#include <list>
#include <sstream>
#include <algorithm>  
#include <iostream>
using namespace std;


void printFunction (Enemy& enemy) { 
     cout <<  enemy.GetName() << endl;
}



////////////////////////////////////////////////////////////////////////////////
class DarkForest : public Room{

private:  
  Enemy* currentEnemy;
  list<Enemy> enemiesList;
  bool noticedPlayer;

public:
  DarkForest(){

      currentEnemy = new Enemy();
      noticedPlayer = false;
    
      SetDescription("You are completely lost, and find yourself out in some very very dark place....");
    
      for (int i = 0; i != 4; i++){
        
            Enemy e;

            switch (i)
            { 
              case 0:
                e.SetName("Dark elf");
                e.SetHitpoints(i);
                enemiesList.push_back(e);
                break;

              case 1:
                e.SetName("Angry Dark elf");
                e.SetHitpoints(i);
                enemiesList.push_back(e);
                break;

              case 2:
                e.SetName("Dark elf wizard");
                e.SetHitpoints(i);
                enemiesList.push_back(e);
                break;

              case 3:
                e.SetName("King of Elves"); // Elves :) 
                e.SetHitpoints(i);
                enemiesList.push_back(e);
                break;
            }
            
          // Enemy e;
        
          // ostringstream s;
          // s <<  "Dark Elf " << endl; //<< i; //add number to the stream
          // e.SetName(s.str());
          // e.SetHitpoints(i);
          // enemiesList.push_back(e);

        }


        //Why doesn't this code work here. but works in Update()?
       /////////////////////////////////////////////////////////////////////
       //for_each(enemiesList.begin(), enemiesList.end(), printFunction);//
      /////////////////////////////////////////////////////////////////////

  }
  void Update() {

      // for(list<Enemy>::iterator it = enemiesList.begin(); it != enemiesList.end(); it++)
      // { 
      //   ostringstream s;
      //   if (it->IsAlive()){
      //     s << "Alive: " << it->GetName() << endl;         
      //   }
      //   else{
      //     s << "Dead: " << it->GetName() << endl;  
      //   }
      //   GetGame()->GetRenderer()->Render(s.str());
      // }

      /////////////////////////////////////////////////////////////////////
      // for_each(enemiesList.begin(), enemiesList.end(), printFunction);//
      /////////////////////////////////////////////////////////////////////

      for_each(enemiesList.begin(), enemiesList.end(), printFunction);

      for(list<Enemy>::iterator it = enemiesList.begin(); it != enemiesList.end(); it++)
      { 

        if (it->IsAlive()){
            
            currentEnemy = &*it;
            break; //it doesn't matter who eles is alive
        }
        
      }

      // cout << currentEnemy->GetName() << endl;


        
      if ( currentEnemy->IsAlive() && noticedPlayer )
      { 
          std::ostringstream s;
          Player & player = GetGame()->GetPlayer();
          s << currentEnemy->GetName() << " (" << currentEnemy->GetHitpoints() << "HP)" << " attacks " << player.GetName() << "\n";
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
      s << player.GetName() << "(" << player.GetHitpoints() << " HP)" << " attacks " << currentEnemy->GetName() <<"\n";
      GetGame()->GetRenderer()->Render(s.str());
      player.Attack( currentEnemy );
      // Change room description a bit
      if ( currentEnemy->IsAlive() == false )
      {
         SetDescription("You are in the dark foret. Somethings strange is going on.");
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
