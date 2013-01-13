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
	
	ofstream myfile;
	myfile.open("ResourceFiles/savedata.txt");
	myfile << p.GetName();
	myfile << p.GetRace();
	myfile << p.GetClass();
	myfile << p.GetAge();
	myfile << p.GetGender();
	myfile << p.GetExperience();
	myfile.close();
	}
};
#endif