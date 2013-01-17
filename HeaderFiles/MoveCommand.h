////////////////////
/// Advanced C++
/// Adventure Game 2 
/// Malkov/Danchenkov
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
