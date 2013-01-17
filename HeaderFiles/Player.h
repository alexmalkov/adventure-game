////////////////////
/// Advanced C++
/// Adventure Game 2 
/// Malkov/Danchenkov
////////////////////
#ifndef __Player_h__
#define __Player_h__
#include <string>
#include "GameObject.h"
class Game;
////////////////////////////////////////////////////////////////////////////////
class Player : public GameObject
{
private:
  Game *game;
  int goldAmount;
public:
  Player();

  virtual ~Player();
  void SetGame( Game * game );
  void Attack( GameObject *pObject);
  void SetGoldAmount(int ga);
  int GetGoldAmount();

  void PrintSummary();
  static void AskInfo( Player & p );
};
////////////////////////////////////////////////////////////////////////////////
#endif
