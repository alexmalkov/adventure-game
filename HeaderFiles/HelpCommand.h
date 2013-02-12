////////////////////
/// Advanced C++
/// Adventure Game 3
/// Malkov/Danchenkov
////////////////////
#ifndef __HelpCommand_h__
#define __HelpCommand_h__
#include "Command.h"
#include "Game.h"
////////////////////////////////////////////////////////////////////////////////
class HelpCommand : public Command 
{
public:
  HelpCommand( Game *pGame ) : Command(pGame){}
  void Execute()
  {
	std::ostringstream s;
	s<<"\nList of commands:\n"
	<<"search\n"
	<<"move <direction>\n"
	<<"attack\n"
	<<"save\n"
	<<"load\n"
	<<"showgold\n"
	<<"showsilver\n"
	<<"map\n"
	<<"quit\n\n";
	GetGame()->GetRenderer()->Render(s.str());
  }
};
////////////////////////////////////////////////////////////////////////////////
#endif
