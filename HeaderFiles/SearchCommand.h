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
    if ( rand()%1000 < 436 )
    {
	  Game *game = GetGame();
	  Player & p = game->GetPlayer();
     
	  GoldFactory f;
      Gold *g = f.Create( 1+rand()%100 );
      std::ostringstream s;
      
    
      p.SetGoldAmount(p.GetGoldAmount()+g->GetAmount());
      
      s << "You found " << g->GetAmount() << " gold!\nTotal: " << p.GetGoldAmount() << endl;
	 
      	  
	  GetGame()->GetRenderer()->Render(s.str());
	   
	  
      delete g;
    }
    else {
      GetGame()->GetRenderer()->Render( "You found nothing.\n");
    }
  }
};
////////////////////////////////////////////////////////////////////////////////
#endif
