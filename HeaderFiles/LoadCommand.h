////////////////////
/// Advanced C++
/// Adventure Game 2 
/// Malkov/Danchenkov
////////////////////
#ifndef __LoadCommand_h__
#define __LoadCommand_h__
#include "Command.h"
#include "Game.h"
#include <fstream>

// Load player data from a text file
class LoadCommand : public Command
{
public:
	LoadCommand(Game *pGame):Command(pGame){}
	void Execute()
	{
		Game *g = GetGame();
		Player & p = g->GetPlayer();
		bool fileFound;
		
		try
		{
			// create stream
			ifstream f("ResourceFiles/savedata.txt");
			
			// if the state of the stream is good for I/O operations
			if(!f.good())
			{
			// throw an exception(break and go to catch)
			throw 7;
			}
			fileFound=true;
			// while it is not the end of file
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
					f>>i;p.SetGoldAmount(i);
					f>>i;p.SetSilverAmount(i);
				}	
			}
		}
		catch(...)
		{cout<<"Exception:File is not found"<<endl;}
		// output data if file is found
		if(fileFound)
		{
			cout<<"Name: "<<p.GetName()<<endl;
			cout<<"Race: "<<p.GetRace()<<endl;
			cout<<"Class: "<<p.GetClass()<<endl;
			cout<<"Age: "<<p.GetAge()<<endl;
			cout<<"Gender: "<<p.GetGender()<<endl; //replace hard code
			cout<<"Experience "<<p.GetExperience()<<endl;
			cout<<"Gold amount: "<<p.GetGoldAmount() << endl;
			cout<<"Siver amount: "<<p.GetSilverAmount() << endl;
		}
	}
	
};
#endif
