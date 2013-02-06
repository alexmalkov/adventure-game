////////////////////
/// Advanced C++
/// Adventure Game 2 
/// Malkov/Danchenkov
////////////////////
#ifndef __SearchCommand_h__
#define __SearchCommand_h__
#include <cstdlib>
#include "GoldFactory.h"
#include "SilverFactory.h"
#include "Gold.h"
#include "Silver.h"
#include "Game.h"
#include <sstream>
#include "IRenderer.h"
#include <typeinfo> 
////////////////////////////////////////////////////////////////////////////////
class SearchCommand : public Command
{
public: 
  SearchCommand( Game *pGame ) : Command(pGame) {}
  
  // template <typename T>
	 //  void sum(Player& p, T m)
	 //  {
		// p + m->GetAmount();		
	 //  }
  
  void Execute() 
  { 
	  
	Game *game = GetGame();
	Player & p = game->GetPlayer(); 
 
	//80% that you get money instead of being robbed
    if ( rand()%1000 < 800 )
    {
		std::ostringstream s;

		//60% that you get siver 
		if (rand()%1000<600)
		{

		   SilverFactory sf;
		   Silver *sil = sf.Create( 1+rand()%50 );
		   int SilverFromFactory;
		   SilverFromFactory = sil->GetAmount();


		    p.SetSilverAmount(p.GetSilverAmount() + SilverFromFactory);
		    s << "You found " << SilverFromFactory << " silver!\nTotal silver: " << p.GetSilverAmount() << endl;

		    delete sil;
		}
		else
		{
			GoldFactory f;
			Gold *g = f.Create( 1+rand()%10 );
			p + g->GetAmount();  
			int GoldFromFactory;
			GoldFromFactory = g->GetAmount();
			s << "You found " << g->GetAmount() << " gold!\nTotal gold: " << p.GetGoldAmount() << endl;
			delete g;
		}
      	  
	  GetGame()->GetRenderer()->Render(s.str());   
	  
     
    }
    else {
			
		 std::ostringstream s;
		  //Generate random number
		  //range between 1-30 
		 int stealPower = rand()%20 + 1;
		 Robbers pRob(stealPower );
		  
		 p - pRob;
		 
		 
		 //want to implement option when just nothing happens 
		 // e.g. 80% - find gold 10% - robbers and 10% - nothing
		 // + if you were killed you can start a new game by click 
		 // a certain option
     	 if (p.GetGoldAmount() >= 0)
		 {
			s << "You have met a very cruel and greedy bandits\n" 
			<< "They were about to kill you, but you paid for your life\n" 
			<< "It cost you: " << stealPower << " gold(s)" << endl;
		 }  
		 else
		 {  	
			p.SetHitpoints(-1);
			s << "You meet very cruel and greedy bandits\n" 
			<< "You have not enough gold to pay off.\n"
			<< "Then, fight has begun, you kill 1 big guy,\n"
			<< "suddenly you feel a strong pain in your chest and\n"
			<< "blood starts flowing over your body\n" 
			<< "you see two arrows sticking out from your chest and left leg.\n"
			<< "You cannot move properly and just fall down on the ground.\n"
			<< "You are hearing how bandits slowly gather around you.\n";
		 }
		GetGame()->GetRenderer()->Render(s.str());
	}
  }
};
////////////////////////////////////////////////////////////////////////////////
#endif
