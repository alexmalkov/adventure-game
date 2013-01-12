////////////////////
/// C++ Object-oriented Programming
/// Adventure Game 6
/// Reference answer 
/// anssi.grohn@pkamk.fi
////////////////////
#ifndef __MoveCommand_h__
#define __MoveCommand_h__
#include "Command.h"
#include "globals.h"
////////////////////////////////////////////////////////////////////////////////
class MoveCommand : public Command 
{
private:
  Direction direction; ///< Movement direction.
public:
  MoveCommand( Game *pGame ) : Command(pGame) { }

  void SetDirection( Direction d ) { direction = d; }
  Direction GetDirection() const { return direction; }

  void Execute();

};
////////////////////////////////////////////////////////////////////////////////

#endif
