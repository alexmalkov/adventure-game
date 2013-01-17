////////////////////
/// Advanced C++
/// Adventure Game 2 
/// Malkov/Danchenkov
////////////////////
#ifndef __Command_h__
#define __Command_h__
#include "ICommand.h"
////////////////////////////////////////////////////////////////////////////////
class Game;
class Command : public ICommand
{
private:
  // Pointer to game
  Game *m_pGame;
public:
  // Parametrized constructor.
  Command( Game *pGame ) : m_pGame(pGame){}

  // Accessor
  Game * GetGame() { return m_pGame; }
  // Mutator
  void SetGame( Game *pGame ) { m_pGame = pGame; }

};
////////////////////////////////////////////////////////////////////////////////
#endif
