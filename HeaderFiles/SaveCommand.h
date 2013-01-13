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
	f<< p.GetName()<<endl;
	f<< p.GetRace()<<endl;
	f<< p.GetClass()<<endl;
	f<< p.GetAge()<<endl;
	//char c;
	//if(p.GetGender==0){
	//c='m';}
	//else {
	//c='f';}
	f<<'m'<<endl;
	f<< p.GetExperience();
	f.close();
	}
};
#endif