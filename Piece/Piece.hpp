#ifndef _PIECE_H_
#define _PIECE_H_

#include <iostream>
#include <string>
#include <vector>
#include "raylib.h"
#include "../globals.hpp"

using namespace std;

class Piece{
    protected:
        Coordinate position; 
        string name;
        Side color;
        PieceSpriteId pid;
        bool captured;
        bool moved;
    
    public:
        Piece();
        virtual ~Piece();
        Piece( Coordinate p, string n, Side c, PieceSpriteId id);
        virtual vector<Coordinate> possibleMoves(const vector<Piece*> &) = 0;
        void move(Coordinate p);
        void setPos(Coordinate p);
        string getName() const;
        Coordinate getPosition() const;
        PieceSpriteId getPieceId() const;
        Side getColor() const;
        bool isCaptured() const;
        void capture();
        bool hasMoved() const;
};

class Queen: public Piece{
    public:
        Queen(Coordinate position, Side color) : Piece(position, "Queen", color, (PieceSpriteId)(color*6 + 1)){}
        vector<Coordinate> possibleMoves(const vector<Piece*> &);
};

class King: public Piece{
    public:
        King(Coordinate position, Side color) : Piece(position, "King", color, (PieceSpriteId)(color*6 + 0)){}
        vector<Coordinate> possibleMoves(const vector<Piece*> &);
};

class Bishop: public Piece{
    public:
        Bishop(Coordinate position, Side color) : Piece(position, "Bishop", color, (PieceSpriteId)(color*6 + 2)){}
        vector<Coordinate> possibleMoves(const vector<Piece*> &);
};

class Knight: public Piece{
    public:
        Knight(Coordinate position, Side color) : Piece(position, "Knight", color, (PieceSpriteId)(color*6 + 3)){}
        vector<Coordinate> possibleMoves(const vector<Piece*> &);
};

class Rook: public Piece{
    public:
        Rook(Coordinate position, Side color) : Piece(position, "Rook", color, (PieceSpriteId)(color*6 + 4)){}
        vector<Coordinate> possibleMoves(const vector<Piece*> &);
};

class Pawn: public Piece{
    public:
        Pawn(Coordinate position, Side color) : Piece(position, "Pawn", color, (PieceSpriteId)(color*6 + 5)){}
        vector<Coordinate> possibleMoves(const vector<Piece*> &);
};

#endif