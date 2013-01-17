////////////////////
/// Advanced C++
/// Adventure Game 2 
/// Malkov/Danchenkov
////////////////////
#ifndef __Enemy_h__
#define __Enemy_h__
#include "GameObject.h"
#include <iostream>
#include <cstdlib>
const int ENEMY_DEFAULT_HITPOINTS = 3;

using namespace std;

class Enemy : public GameObject
{
public:

  Enemy() 
  {
    SetHitpoints(ENEMY_DEFAULT_HITPOINTS) ;
  }
  
  bool IsAlive() const { return GetHitpoints() > 0; }

  void Attack( GameObject *pObject )
  {
    int hp = pObject->GetHitpoints();
    if ( (rand() % 10) < 3 )
    {
      // TODO: convert this into weapon 
      // with damage property. Can you do it? Is so, explain in your learning diary how.
      pObject->SetHitpoints(hp-1); 
      cout << GetName() << " hits!\n";
    }
    else
      cout << GetName() << " misses!\n";
  }
};

#endif
