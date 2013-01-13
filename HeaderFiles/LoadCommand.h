////////////////////
/// Advanced C++
/// Adventure Game 2 
/// Malkov/Danchenkov
////////////////////
#ifndef LOADCOMMAND_H
#define LOADCOMMAND_H
#include "Command.h"
#include "Game.h"

class LoadCommand : public Command
{
public:
	LoadCommand(Game *pGame):Command(pGame){}
	void Execute()
	{
		Player p = pGame.GetPlayer();
		ifstream f(ResourceFiles/savedata.txt);
		while(!f.eof())
		{
			string line;
			f >> line;
			if(line=="#player")
			{
				int i;
				string s;
				char c;
				f>>s;p.SetName(str);
				f>>s;p.SetRace(str);
				f>>i;p.SetClass((Class)i);
				f>>s;p.SetAge(i);
				f>>c;p.SetGender((c=='m'?Male:Female));
				f>>i;p.SetExperience(i);
			}
		}
	}
};
#endif