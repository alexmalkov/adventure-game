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
		Game *g = GetGame();
		Player p = g->GetPlayer();
		ifstream f("ResourceFiles/savedata.txt");
		while(!f.eof())
		{
			string line;
			f >> line;
			if(line=="#player")
			{
				int i;
				string s;
				char c;
				f>>s;p.SetName(s);
				f>>s;p.SetRace(s);
				f>>i;p.SetClass((Class)i);
				f>>i;p.SetAge(i);
				f>>c;p.SetGender((c=='m'?Male:Female));
				f>>i;p.SetExperience(i);
			}	
		}
		cout<<p.GetName()<<endl;
		cout<<p.GetRace()<<endl;
		cout<<p.GetClass()<<endl;
		cout<<p.GetAge()<<endl;
		cout<<"m"<<endl;
		cout<<p.GetExperience()<<endl;
	}
};
#endif