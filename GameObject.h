////////////////////
/// C++ Object-oriented Programming
/// Adventure Game 6
/// Reference answer 
/// anssi.grohn@pkamk.fi
////////////////////
#ifndef __GameObject_h__
#define __GameObject_h__
#include <string>
#include "Updateable.h"
#include "Attacker.h"
////////////////////////////////////////////////////////////////////////////////
using std::string;
enum Gender { Male, Female };
enum Class { Barbarian, Wizard, Paladin, Priest };
////////////////////////////////////////////////////////////////////////////////
/// Base class for all game characters.
class GameObject : public Attacker, public Updateable
{
private:
  string name;
  string race;
  Class myClass;
  unsigned short int age;
  Gender gender;
  int experience;
  int hitpoints;
public:

  GameObject();
  virtual ~GameObject();
  void SetName( string name) ;
  string GetName() const;

  void SetClass( Class c);
  Class GetClass() const;

  void SetAge( unsigned short int age );
  unsigned short int GetAge() const;
  
  void SetGender( Gender g );
  Gender GetGender() const;
  
  void SetRace( string r );
  string GetRace() const;
  
  void SetExperience( int experience );
  int GetExperience() const;
  
  void Attack( GameObject *pObject );

  int GetHitpoints() const;
  void SetHitpoints(int hp );

  void Update();
};

#endif
