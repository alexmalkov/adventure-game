cd SourceFiles
g++ -c adventure.cpp AttackCommand.cpp Game.cpp Gold.cpp GoldFactory.cpp Player.cpp GameObject.cpp CommandFactory.cpp MoveCommand.cpp Room.cpp -I ../HeaderFiles

g++ -shared -o ../bin/Engine.dll AttackCommand.o Gold.o GoldFactory.o GameObject.o CommandFactory.o MoveCommand.o Room.o Game.o Player.o -Wl,--out-implib,Engine.a

g++ -o adventure.o ../GameDyn.exe -L ../bin -lEngine -I ../HeaderFiles