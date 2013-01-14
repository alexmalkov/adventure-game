////////////////////
/// Advanced C++
/// Adventure Game 2 
/// Malkov/Danchenkov
////////////////////
#ifndef SAVECOMMAND_H
#define SAVECOMMAND_H
#include "Command.h"
#include "Game.h"
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

class SaveCommand : public Command
{
public:
	SaveCommand(Game *pGame):Command(pGame){}
	void Execute()
	{
	Game *g = GetGame();
	Player p = g->GetPlayer();
	
	ofstream f;
	f.open("ResourceFiles/savedata.txt");
	f<<"#player"<<endl;
	f<< p.GetName()<<endl;
	f<< p.GetRace()<<endl;
	f<< p.GetClass()<<endl;
	f<< p.GetAge()<<endl;
	f<<'m'<<endl;
	f<< p.GetExperience();
	f.close();
	}
};
#endif