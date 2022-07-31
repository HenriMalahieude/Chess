#ifndef _GRAPH_ICS_HANDL_
#define _GRAPH_ICS_HANDL_

#include "raylib.h"
#include "../globals.hpp"
#include "../Piece/Piece.hpp"
#include <algorithm>

using namespace std;

const Rectangle pieceSpriteLocations[12] = {
	Rectangle{0, 0, squareSize, squareSize}, //White King ID = 0
	Rectangle{squareSize, 0, squareSize, squareSize}, //White Queen
	Rectangle{squareSize*2, 0, squareSize, squareSize}, //White Bishop
	Rectangle{squareSize*3, 0, squareSize, squareSize}, //White Knight
	Rectangle{squareSize*4, 0, squareSize, squareSize}, //White Rook
	Rectangle{squareSize*5, 0, squareSize, squareSize}, //White Pawn

	Rectangle{0, squareSize, squareSize, squareSize}, //Black King ID = 7
	Rectangle{squareSize, squareSize, squareSize, squareSize}, //Black Queen
	Rectangle{squareSize*2, squareSize, squareSize, squareSize}, //Black Bishop
	Rectangle{squareSize*3, squareSize, squareSize, squareSize}, //Black Knight
	Rectangle{squareSize*4, squareSize, squareSize, squareSize}, //Black Rook
	Rectangle{squareSize*5, squareSize, squareSize, squareSize}, //Black Pawn
};

void drawBoard();
void drawTimer(int sec1, int sec2);//, Texture2D &);

void drawPieces(const vector<Piece*> &pieces, Texture2D &loadedSprite);
void updateCaptured(const vector<Piece*> &pieces, Texture2D &loadedSprite);

//Format Mouse Position
Coordinate BoardGridFormat(int mX, int mY);

#endif