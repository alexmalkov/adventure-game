////////////////////
/// Advanced C++
/// Adventure Game 2 
/// Malkov/Danchenkov
////////////////////
#ifndef __SearchCommand_h__
#define __SearchCommand_h__
#include <cstdlib>
#include "GoldFactory.h"
#include "Gold.h"
#include "Game.h"
#include <sstream>
#include "IRenderer.h"
////////////////////////////////////////////////////////////////////////////////
class SearchCommand : public Command
{
public: 
  SearchCommand( Game *pGame ) : Command(pGame) {}
  
  void Execute() 
  { 
	  
	Game *game = GetGame();
	Player & p = game->GetPlayer();      
	  
    if ( rand()%1000 < 80 )
    {
	  	  

     
	  GoldFactory f;
      Gold *g = f.Create( 1+rand()%10 );
      std::ostringstream s;
      
      int GoldFromFactory;
      GoldFromFactory = g->GetAmount();
      
      p + GoldFromFactory; // operator + is overloaded
      
      s << "You found " << g->GetAmount() << " gold!\nTotal: " << p.GetGoldAmount() << endl;
	 
      	  
	  GetGame()->GetRenderer()->Render(s.str());
	   
	  
      delete g;
    }
    else {
			
		 std::ostringstream s;
		  //Generate random number
		  //range between 1-30 
		 int steelPower = rand()%20 + 1;
		 Robbers pRob(steelPower );
		  
		 p - pRob;
		 
		 
		 //want to implement option when just nothing happens 
		 // e.g. 80% - find gold 10% - robbers and 10% - nothing
		 // + if you were killed you can start a new game by click 
		 // certain option
     	 if (p.GetGoldAmount() >= 0)
		 {
			s << "You have met a very cruel and greedy bandits\n" 
			<< "They were about to kill you, but you paid for your life\n" 
			<< "It cost you: " << steelPower << " gold(s)" << endl;
		 }  
		 else
		 {  	
			p.SetHitpoints(-1);
			s << "You meet a very cruel and greedy bandits\n" 
			<< "You have not enough gold to pay off.\n"
			<< "Then, fight has begun, you kill 1 big guy,\n"
			<< "suddenly you feel a strong pain in your chest and\n"
			<< "blood start flowing over your body\n" 
			<< "you see two arrows stick out from your chest and left leg.\n"
			<< "You cannot move properly and just fall down on the ground.\n"
			<< "You are hearing how bandits slowly gather around you.\n";
		 }
		GetGame()->GetRenderer()->Render(s.str());
	}
  }
};
////////////////////////////////////////////////////////////////////////////////
#endif
