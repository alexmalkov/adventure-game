////////////////////
/// Advanced C++
/// Adventure Game 2 
/// Malkov/Danchenkov
////////////////////
#ifndef __Player_h__
#define __Player_h__
#include <string>
#include "GameObject.h"
#include "Robbers.h"
#include <vector>
#include <iostream>
using namespace std;
class Game;
////////////////////////////////////////////////////////////////////////////////
class Player : public GameObject
{
private:
  Game *game;
  int goldAmount;
  int silverAmount;

public:
  Player();
  vector<int> silHistory;

  virtual ~Player();
  void SetGame( Game * game );
  void Attack( GameObject *pObject);
  void SetGoldAmount(int ga);
  int GetGoldAmount();
  void SetSilverAmount(int sa);
  int GetSilverAmount();
  
  Player & operator+ (int value);
  Player & operator- (Robbers & pRob);
  

  void PrintSummary();
  static void AskInfo( Player & p );
};
////////////////////////////////////////////////////////////////////////////////
#endif
