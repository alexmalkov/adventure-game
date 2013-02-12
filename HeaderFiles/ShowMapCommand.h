////////////////////
/// Advanced C++
/// Adventure Game 
/// Malkov/Danchenkov
////////////////////
#ifndef SHOWMAPCOMMAND_H
#define SHOWMAPCOMMAND_H
#include "Command.h"
#include "Game.h"

using namespace std;

class ShowMapCommand : public Command
{
public:
	ShowMapCommand(Game * pGame):Command(pGame){}
	void Execute()
	{
		cout<<"					 _______\n";
		cout<<"					|Prin	|\n";
		cout<<"					|	cess|\n";
		cout<<"					|__   __|\n";
		cout<<"					 __| |__\n";
		cout<<"					|		|";
		cout<<"					|		|";
		cout<<"	 _______		|__   __|		 _______";
		cout<<"	|		|		   | |			|		|";
		cout<<"	|		|__________| |__________|		|";
		cout<<"	|		 _______   	 	 _______		|";
		cout<<"	|		|		|	    |		|		|";
		cout<<"	|_______|		|__   __|		|_______|";
		cout<<"					   | |";
		cout<<"					 __| |__";
		cout<<"					|   	|";
		cout<<"					|  		|";
		cout<<"					|   	|";
		cout<<"					|		|";
		cout<<"					|+++++++|";
	}
};
#endif