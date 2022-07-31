CC = em++
UNUSED = -O2 -Wall -Wno-missing-braces -I ./include/ -L ./lib/ -lraylib -lopengl32 -lgdi32 -lwinmm
FLAGS = -O2 -Wall -I ./include/ -L ./lib/ -lraylib -s USE_GLFW=3 -s ASYNCIFY -DPLATFORM_WEB -std=c++17 --preload-file resources/

all: ./Visuals.o ./Piece.o ./GameBoard.o ./Check.o
	$(CC) ../main.cpp ./visuals.o ./Piece.o ./GameBoard.o ./Check.o -o Chess.html $(FLAGS)

Visuals.o: ../Visuals/Visuals.cpp
	$(CC) ../Visuals/Visuals.cpp -c $(FLAGS)

Piece.o: ../Piece/Piece.cpp
	$(CC) ../Piece/Piece.cpp -c $(FLAGS)

GameBoard.o: ../GameBoard/GameBoard.cpp
	$(CC) ../GameBoard/GameBoard.cpp -c $(FLAGS)

Check.o: ../Check/Check.cpp
	$(CC) ../Check/Check.cpp -c $(FLAGS)