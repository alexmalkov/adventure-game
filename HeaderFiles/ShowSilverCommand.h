////////////////////
/// Advanced C++
/// Adventure Game 2 
/// Malkov/Danchenkov
////////////////////
#ifndef SHOWSILVERCOMMAND_H
#define SHOWSILVERCOMMAND_H
#include "Command.h"
#include "Game.h"

using namespace std;

class ShowSilverCommand : public Command
{
public:
	ShowSilverCommand(Game *pGame):Command(pGame){}
	void Execute()
	{
	Game *g = GetGame();
	Player p = g->GetPlayer();
	
	cout<< p.GetSilverAmount() << " silver" <<endl;
	}
}; 
#endif
