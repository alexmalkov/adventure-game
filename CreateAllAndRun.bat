cd SourceFiles
g++ -c adventure.cpp AttackCommand.cpp Game.cpp Gold.cpp GoldFactory.cpp Player.cpp GameObject.cpp CommandFactory.cpp MoveCommand.cpp Room.cpp -I ../HeaderFiles

ar rcs ../bin/libEngine.a AttackCommand.o Gold.o GoldFactory.o GameObject.o CommandFactory.o MoveCommand.o Room.o


g++ adventure.o game.o player.o -L ../bin -lEngine -o ../Game.exe

cd ../

Game.exe