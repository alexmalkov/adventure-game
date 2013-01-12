cd SourceFiles
g++ -c adventure.cpp AttackCommand.cpp Game.cpp Gold.cpp GoldFactory.cpp Player.cpp GameObject.cpp CommandFactory.cpp MoveCommand.cpp Room.cpp -I ../HeaderFiles

g++ adventure.o AttackCommand.o Game.o MoveCommand.o Player.o Room.o -L ../bin -lEngine -o ../AdventureGame.exe


cd ../

AdventureGame.exe