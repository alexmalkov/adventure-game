////////////////////
/// Advanced C++
/// Adventure Game 2 
/// Malkov/Danchenkov
////////////////////
#ifndef __SaveCommand_h__
#define __SaveCommand_h__
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
	
	// temporary stuff
	// remove savedata.txt if exists to check if it matters for
	// writing wrong goldAmount into file
	if( remove( "ResourceFiles/savedata.txt" ) != 0 )
    {perror( "Error deleting file" );}
	else
    {puts( "File successfully deleted" );}
  
	// create and start using file
	f.open("ResourceFiles/savedata.txt");
	// wtite data to the file
	f<<"#player"<<endl;
	f<< p.GetName()<<endl;
	f<< p.GetRace()<<endl;
	f<< p.GetClass()<<endl;
	f<< p.GetAge()<<endl;
	
	//f<<'m'<<endl; //Hard code??? - Yeah, could not handle it fast,
	// but wanted to see gender as a word..
	// That looked better than 0 and didn't spoil anything
	// since it was clear from other stuff how to use getters and
	// write data into file. Now we don't have gender displayed at all.
	
	f<<p.GetGender();
	f<< p.GetExperience();
	f<< p.GetGoldAmount();
	// close the stream
	f.close();
	}
};
#endif
