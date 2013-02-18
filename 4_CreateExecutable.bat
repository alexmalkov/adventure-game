cd SourceFiles
g++ -std=c++0x adventure.o game.o player.o -L ../bin -lEngine -o ../Game.exe

pause