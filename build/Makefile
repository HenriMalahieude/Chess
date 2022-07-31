CC = em++
UNUSED = -O2 -Wall -Wno-missing-braces -I ./include/ -L ./lib/ -lraylib -lopengl32 -lgdi32 -lwinmm
FLAGS = -O2 -Wall -I ./include/ -L ./lib/ -lraylib -s USE_GLFW=3 -s ASYNCIFY -DPLATFORM_WEB -std=c++17 --preload-file resources/

all: ./Visuals.o ./Piece.o ./GameBoard.o ./Check.o
	$(CC) ../src/main.cpp ./visuals.o ./Piece.o ./GameBoard.o ./Check.o -o index.html $(FLAGS)

Visuals.o: ../src/Visuals/Visuals.cpp
	$(CC) ../src/Visuals/Visuals.cpp -c $(FLAGS)

Piece.o: ../src/Piece/Piece.cpp
	$(CC) ../src/Piece/Piece.cpp -c $(FLAGS)

GameBoard.o: ../src/GameBoard/GameBoard.cpp
	$(CC) ../src/GameBoard/GameBoard.cpp -c $(FLAGS)

Check.o: ../src/Check/Check.cpp
	$(CC) ../src/Check/Check.cpp -c $(FLAGS)