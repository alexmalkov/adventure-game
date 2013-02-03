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
#include <iostream>
using namespace std;
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
      
        ostringstream s;
        s <<  "Dark Elf "  << i; //add number to the stream
        e.SetName(s.str());
        e.SetHitpoints(5);
        enemiesList.push_back(e);
    }
  }
  void Update() {

      for(list<Enemy>::iterator it = enemiesList.begin(); it != enemiesList.end(); it++)
      { 

        ostringstream s;
        if (it->IsAlive()){
          s << "Alive: " << it->GetName() << endl;         
        }
        else{
          s << "Dead: " << it->GetName() << endl;  
        }
        GetGame()->GetRenderer()->Render(s.str());
      }

      for(list<Enemy>::iterator it = enemiesList.begin(); it != enemiesList.end(); it++)
      { 

        if (it->IsAlive()){
            
            currentEnemy = &*it;
            break; //it doen't matter who eles is alive
        }
        
      }

      cout << currentEnemy->GetName() << endl;


        
      if ( currentEnemy->IsAlive() && noticedPlayer )
      { 
          std::ostringstream s;
          Player & player = GetGame()->GetPlayer();
          s << currentEnemy->GetName() << " attacks " << player.GetName() << "\n";
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
  
  // void OnAttack( AttackCommand *pCommand )
  // {
  //   if ( e.IsAlive() && noticedPlayer)
  //   {
  //     Player & player = GetGame()->GetPlayer();
  //     std::ostringstream s;
  //     s << player.GetName() << " attacks " << e.GetName() << "\n";
  //     GetGame()->GetRenderer()->Render(s.str());
  //     player.Attack( &e );
  //     // Change room description a bit
  //     if ( e.IsAlive() == false )
  //     {
  //        SetDescription("You are in the monster room. There is a pretty dead orc here.");
  //     }
  //   } 
  //   else 
  //   {
  //     // to encourage player to stop beating it further
  //     GetGame()->GetRenderer()->Render("Whoa! You already got your pound of flesh out of that one. Literally.\n");
  //   }

  // }






};
////////////////////////////////////////////////////////////////////////////////
#endif
