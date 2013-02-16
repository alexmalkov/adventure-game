////////////////////
/// Advanced C++
/// Adventure Game 2 
/// Malkov/Danchenkov
////////////////////
#ifndef __Lurk_h__
#define __Lurk_h__
#include "Command.h"
#include "Game.h"
#include "DarkForest.h"
using namespace std;

/////////////////////////////////////////////////////////////////////////////////
struct Print {
  //Functor
  void operator()( Enemy & enemy ) { 
    
      if(enemy.IsAlive())
      {
        cout << "Alive: ";
        cout << enemy.GetName() << " (HP:" << enemy.GetHitpoints() << ")" << endl;
      }
      else
      {
        cout <<"Dead: ";
        cout << enemy.GetName() << endl;
      }
      
  }
};


////////////////////////////////////////////////////////////////////////////////
class LurkCommand : public Command
{
public:
	LurkCommand(Game *pGame) : Command(pGame){};

	void Execute ()
	{
    Print print;
    //Print p;
		vector<Enemy> * enemyVector =  GetGame()->GetCurrentRoom()->GetEnemyVector();

    //for_each
    for_each(enemyVector->begin(), enemyVector->end(),print);

	}

  


};


////////////////////////////////////////////////////////////////////////////////
#endif
