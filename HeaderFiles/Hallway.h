////////////////////
/// C++ Object-oriented Programming
/// Adventure Game 6
/// Reference answer 
/// anssi.grohn@pkamk.fi
////////////////////
#ifndef __Hallway_h__
#define __Hallway_h__
#include "Room.h"
#include <sstream>
////////////////////////////////////////////////////////////////////////////////
class Hallway : public Room
{
public:
  Hallway()
  {
    SetDescription("You are standing in a pretty damp hallway.");
  }
  
  void Update()
  {
    
  }
};
////////////////////////////////////////////////////////////////////////////////
#endif
