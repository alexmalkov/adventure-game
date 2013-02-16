////////////////////
/// Advanced C++
/// Adventure Game 2 
/// Malkov/Danchenkov
////////////////////
#ifndef __CallCommand_h__
#define __CallCommand_h__
#include "Command.h"
#include "Game.h"
#include "DarkForest.h"
#include <vector>
#include <functional>
using namespace std;
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
class CallCommand : public Command
{
private:
  string _name; 
public:
  CallCommand(Game *pGame) : Command(pGame){};

  void SetName(string name) {_name = name;}
  string GetName(){return _name;}

      bool func (Enemy enemy){
        
          return enemy.GetName() == _name && enemy.IsAlive();

          // cout << enemy.GetName() << endl;
          //   cout << _name << endl;
          //   cout << enemy.IsAlive() << endl;          
      }


  void Execute(){

        vector<Enemy> *enemyVector = GetGame()->GetCurrentRoom()->GetEnemyVector(); 
        vector<Enemy>::iterator it;

        it = find_if(enemyVector->begin(), enemyVector->end(), bind1st(mem_fun(&CallCommand::func), this));
        GetGame()->GetCurrentRoom()->SetCurrentEnemy(&*it);

        cout << _name << endl;        


       //  GetGame()->GetCurrentRoom()->SetCurrentEnemy(&*enemyVector->begin());
       // Enemy * newE = GetGame()->GetCurrentRoom()->GetCurrentEnemy();
       // cout << newE->GetName() << " i !" << endl;
        // cout << "it: " << typeid(it).name() << endl;
        // cout << "*it: " << typeid(*it).name() << endl;
        // cout << "&*it: " << typeid(&*it).name() << endl;
       // cout << GetGame()->GetCurrentRoom()->GetDescription();   

  }


};


////////////////////////////////////////////////////////////////////////////////
#endif
