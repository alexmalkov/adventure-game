g++ -c adventure.cpp AttackCommand.cpp Game.cpp Gold.cpp GoldFactory.cpp Player.cpp GameObject.cpp CommandFactory.cpp MoveCommand.cpp Room.cpp

ar rcs libEngine.a GameObject.o CommandFactory.o GoldFactory.o Gold.o

g++ adventure.o AttackCommand.o Game.o MoveCommand.o Player.o Room.o -L. -lEngine
 
