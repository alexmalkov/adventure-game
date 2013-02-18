del Game.exe GameUsing_DLL.exe Engine.dll
cd bin
del libEngine.a
del Engine.dll
cd ../SourceFiles
del CommandFactory.o Game.o GameObject.o Gold.o GoldFactory.o MoveCommand.o Player.o Room.o adventure.o AttackCommand.o Engine.a
cd ../ResourceFiles
del savedata.txt

cd ../SourceFiles
g++ -c -std=c++0x adventure.cpp AttackCommand.cpp Game.cpp Gold.cpp GoldFactory.cpp Player.cpp GameObject.cpp CommandFactory.cpp MoveCommand.cpp Silver.cpp SilverFactory.cpp Room.cpp -I ../HeaderFiles

ar rcs ../bin/libEngine.a AttackCommand.o Gold.o GoldFactory.o GameObject.o CommandFactory.o MoveCommand.o Room.o Silver.o SilverFactory.o


g++ adventure.o game.o player.o -L ../bin -lEngine -o ../Game.exe

cd ../

Game.exe
pause
