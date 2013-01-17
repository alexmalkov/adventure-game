////////////////////
/// Advanced C++
/// Adventure Game 2 
/// Malkov/Danchenkov
////////////////////
#ifndef __QuitCommand_h__
#define __QuitCommand_h__
#include "Command.h"
#include "Game.h"
////////////////////////////////////////////////////////////////////////////////
class QuitCommand : public Command 
{
public:
  QuitCommand( Game *pGame ) : Command(pGame){}
  void Execute()
  {
    GetGame()->SetRunning(false);
  }
};
////////////////////////////////////////////////////////////////////////////////
#endif
