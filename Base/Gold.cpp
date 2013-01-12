////////////////////
/// C++ Object-oriented Programming
/// Adventure Game 6
/// Reference answer 
/// anssi.grohn@pkamk.fi
////////////////////
#include "Gold.h"
////////////////////////////////////////////////////////////////////////////////
Gold::Gold( unsigned int value) : m_nAmount(value)
{
  
}
////////////////////////////////////////////////////////////////////////////////
Gold::~Gold()
{
  
}
////////////////////////////////////////////////////////////////////////////////
unsigned int 
Gold::GetAmount() const
{
  return m_nAmount;
}
////////////////////////////////////////////////////////////////////////////////
void 
Gold::SetAmount( unsigned int value )
{
  m_nAmount = value;
}
////////////////////////////////////////////////////////////////////////////////
