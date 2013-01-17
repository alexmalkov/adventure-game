////////////////////
/// Advanced C++
/// Adventure Game 2 
/// Malkov/Danchenkov
////////////////////
#ifndef __AttackCommand_h__
#define __AttackCommand_h__
////////////////////////////////////////////////////////////////////////////////
#include "Command.h"
class Game;
#include "Dungeon.h"
#include <sstream>
////////////////////////////////////////////////////////////////////////////////
class AttackCommand  : public Command
{
public:
  AttackCommand( Game *pGame ) : Command(pGame) { }

  
  void Execute();
  /*
  {
    using namespace std;
    ostringstream s;
    Player & player = GetGame()->GetPlayer();
    // Now this is a quick hack - design does not support retrieval of an GameObject from room...
    // And this code works only with Dungeon.
    // \TODO Design a proper solution for this.... (you can describe idea in your learning diary)
    Dungeon *pDungeon = dynamic_cast<Dungeon *>(GetGame()->GetCurrentRoom());

    // If we have a dungeon as current room 
    if ( pDungeon != NULL )
    {
      // Grab enemy
      Enemy & enemy = pDungeon->GetEnemy();
      // iF enemy is alive, make it player attack it
      if ( enemy.GetHitpoints() > 0 )
      {
	s << player.GetName() << " attacks " << enemy.GetName() << "\n";
	GetGame()->GetRenderer()->Render(s.str());
	player.Attack(&enemy);
      } 
      else 
      { 
	// Otherwise show something else
	GetGame()->GetRenderer()->Render("Whoa! You already got your pound of flesh out of that one. Literally.\n");
      }
    }
    else 
    {
      // NO enemy , NO attack possibility
      GetGame()->GetRenderer()->Render("Attack what? There's nothing there!\n");
      }
      }*/
};
////////////////////////////////////////////////////////////////////////////////
#endif
