////////////////////
/// Advanced C++
/// Adventure Game 2 
/// Malkov/Danchenkov
////////////////////
#include "CommandFactory.h"
#include "QuitCommand.h"
#include "SearchCommand.h"
#include "AttackCommand.h"
#include "UnknownCommand.h"
#include "MoveCommand.h"
#include "SaveCommand.h"
#include "LoadCommand.h"
#include "ShowGoldCommand.h"
#include "ShowSilverCommand.h"
#include "ShowMapCommand.h"
#include "SilverFactory.h"
#include "HelpCommand.h"
#include "Game.h"
#include <sstream>
#include <string>
#include <iostream>
////////////////////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////////////////////
ICommand * 
CommandFactory::Create( const std::string & str )
{
  std::istringstream s(str);
  std::string word;
  s >> word;
  
  
  if(word == "help")
  {
	return new HelpCommand(m_pGame);
  }
  
  if(word == "showgold")
  {
	return new ShowGoldCommand(m_pGame);
  }
  
  if(word == "map")
  {
	return new ShowMapCommand(m_pGame);
  }
  
  if(word == "showsilver")
  {
	return new ShowSilverCommand(m_pGame);
  }
  
  if (word == "save")
  {
	return new SaveCommand(m_pGame);
  }
  
  if (word == "load")
  {
	return new LoadCommand(m_pGame);
  }
  
  if ( word == "quit" )
  {
    return new QuitCommand(m_pGame);
  }
  
  if ( word == "search")
  {
    return new SearchCommand(m_pGame);
  }
  
  if ( word == "attack" )
  {
    return new AttackCommand(m_pGame);
  }

  if ( word == "move" )
  {
    string dir;
    s >> dir;
    //cout << "got dir '" << dir << "'\n";
    MoveCommand *command = NULL;
    if ( dir == "north" )
    {
      command = new MoveCommand(m_pGame);
      command->SetDirection(North);
      return command;
    }
    else if ( dir == "south" )
    {
      command = new MoveCommand(m_pGame);
      command->SetDirection(South);
      return command;
    }
    else if ( dir == "east" )
    {
      command = new MoveCommand(m_pGame);
      command->SetDirection(East);
      return command;
    }
    else if ( dir == "west" )
    {
      command = new MoveCommand(m_pGame);
      command->SetDirection(West);
      return command;
    }

  }

  return new UnknownCommand(m_pGame);  
}
////////////////////////////////////////////////////////////////////////////////
