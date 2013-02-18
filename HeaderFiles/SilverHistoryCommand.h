////////////////////
/// Advanced C++
/// Adventure Game
/// Malkov/Danchenkov
////////////////////
#ifndef __SilverHistoryCommand__h__
#define __SilverHistoryCommand__h__
#include "Command.h"
#include "Game.h"
#include "iostream"
#include <vector>
#include "SearchCommand.h"
#include <algorithm>

struct Write {
	void operator() (int i) {
		cout << i << endl;
	}
};

class SilverHistoryCommand : public Command
{
public:
	SilverHistoryCommand(Game *pGame):Command(pGame){}
	void Execute()
	{
		Game *g = GetGame();
		Player &p = g->GetPlayer();

		//*****4 ways how to print all vector members*****//
		//===Irerator+for=======================================//
		/*vector<int>::iterator it = p.silHistory.begin();
		for(;it!=p.silHistory.end();it++)
		{
			cout<<*it<<endl;
		}*/
		//===auto===============================================//
		/*auto it = p.silHistory.begin();
		for(;it!=p.silHistory.end();it++)
		{
			cout<<*it<<endl;
		}*/
		//===for_each+functor===================================//
		/*Write w;
		for_each(p.silHistory.begin(), p.silHistory.end(), w);
		*/
		//===for_each+lambda====================================//
		for_each(p.silHistory.begin(), p.silHistory.end(), [] (int i) {cout<<i<<endl;});
	}
};
#endif