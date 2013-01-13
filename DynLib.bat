cd SourceFiles
g++ -c adventure.cpp AttackCommand.cpp Game.cpp Gold.cpp GoldFactory.cpp Player.cpp GameObject.cpp CommandFactory.cpp MoveCommand.cpp Room.cpp -I ../HeaderFiles

g++ -shared -o ../Engine.dll AttackCommand.o Gold.o GoldFactory.o GameObject.o CommandFactory.o MoveCommand.o Room.o Game.o Player.o

g++ adventure.cpp -o ../GameUsing_DLL.exe -L ../bin -lEngine -I ../HeaderFiles

pause