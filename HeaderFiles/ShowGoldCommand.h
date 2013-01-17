////////////////////
/// Advanced C++
/// Adventure Game 2 
/// Malkov/Danchenkov
////////////////////
#ifndef SHOWGOLDCOMMAND_H
#define SHOWGOLDCOMMAND_H
#include "Command.h"
#include "Game.h"

using namespace std;

class ShowGoldCommand : public Command
{
public:
	ShowGoldCommand(Game *pGame):Command(pGame){}
	void Execute()
	{
	Game *g = GetGame();
	Player p = g->GetPlayer();
	
	cout<<p.GetGoldAmount()<<endl;
	}
}; 
#endif