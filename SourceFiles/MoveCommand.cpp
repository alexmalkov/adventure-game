////////////////////
/// Advanced C++
/// Adventure Game 2 
/// Malkov/Danchenkov
////////////////////
#include "MoveCommand.h"
#include "Game.h"
#include "Room.h"
#include "TextRenderer.h"
////////////////////////////////////////////////////////////////////////////////
void MoveCommand::Execute()
{
  Room *pRoom = GetGame()->GetCurrentRoom();
  if ( pRoom ) {
    Room *newRoom = pRoom->OnMoveCommand(this);
    if ( newRoom )
      GetGame()->SetCurrentRoom(newRoom);
    else
      GetGame()->GetRenderer()->Render( "Cannot go that way\n");
  }
}
////////////////////////////////////////////////////////////////////////////////
