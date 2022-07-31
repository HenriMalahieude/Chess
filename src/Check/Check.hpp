#ifndef __CHECK_H__
#define __CHECK_H__

#include "../Piece/Piece.hpp"

class Check {
    private:
        Piece *whiteKing, *blackKing;

    public:
        Check();
        Check(const vector<Piece*> &);

        ~Check();

        bool isLegalMove(const vector<Piece*> &, Piece*, Coordinate) const;
        bool isKingInCheck(Side, const vector<Piece*> &) const;
        bool kingCanMove(Side, const vector<Piece*> &) const;
        bool otherMoves(Side, const vector<Piece*> &) const;
};

#endif // __CHECK_H__