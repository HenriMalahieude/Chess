#ifndef __GLOBALS_CHESS__
#define __GLOBALS_CHESS__

const int screenWidth = 900;
const int screenHeight = screenWidth;

const int borderEmptySize = 100;

const int boardSize = screenWidth - borderEmptySize;
const int squareSize = boardSize / 8;
const int miniSize = squareSize / 3;
const int boardOffset = (screenWidth - boardSize) / 2; //To get the Board in the center of the window

enum PieceSpriteId {WKing = 0, WQueen, WBishop, WKnight, WRook, WPawn, BKing, BQueen, BBishop, BKnight, BRook, BPawn};

enum Side {White = 0, Black, Neutral};

struct Coordinate{
    int x,y;

    bool operator==(const Coordinate &rhs) const{
        return x == rhs.x && y == rhs.y;
    }
};

#endif