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
// creates a file and saves player data into it
class SaveCommand : public Command
{
public:
	SaveCommand(Game *pGame):Command(pGame){}
	void Execute()
	{
	Game *g = GetGame();
	Player & p = g->GetPlayer();
	// create stream
	ofstream f;
	// create and start using file
	f.open("ResourceFiles/savedata.txt");
	// wtite data to the file
	f<<"#player"<<endl;
	f<< p.GetName()<<endl;
	f<< p.GetRace()<<endl;
	f<< p.GetClass()<<endl;
	f<< p.GetAge()<<endl;
	
	//f<<'m'<<endl; //Hard code???
	
	f<<p.GetGender();
	f<< p.GetExperience();
	f<< p.GetGoldAmount();
	// close the stream
	f.close();
	}
};
#endif
