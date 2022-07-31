#include "Check.hpp"

bool checkDistance(Coordinate a, Coordinate b, double dist){
    double xDiff = (a.x - b.x);
    double yDiff = (a.y - b.y);
    double beforeRoot = xDiff * xDiff + yDiff * yDiff;

    return beforeRoot < (dist*dist);
};

bool canTakeKing(const vector<Piece*> &pieces, Piece* pp, Piece* relatedKing){
    vector<Coordinate> moves = pp->possibleMoves(pieces);

    for (unsigned i = 0; i < moves.size(); i++){
        if (moves.at(i) == relatedKing->getPosition()){
            return true;
        }
    }

    return false;
}

Check::Check(){
    whiteKing = nullptr;
    blackKing = nullptr;
};

Check::Check(const vector<Piece*> &pieces){
    for (unsigned i = 0; i < pieces.size(); i++){
        Piece* pp = pieces.at(i);
        if (pp->getName() == "King"){
            if (pp->getColor() == White){
                whiteKing = pp;
            }else{
                blackKing = pp;
            }
        }
    }
}

Check::~Check(){
    whiteKing = nullptr;
    blackKing = nullptr;
}

bool Check::isLegalMove(const vector<Piece*> &pieces, Piece* piece, Coordinate location) const{
    //cout << "check!\n"; 
    Coordinate savPos = piece->getPosition();
    Piece* capt = nullptr;
    Coordinate captPos = Coordinate{0, 0};

    for (unsigned i = 0; i < pieces.size(); i++){
        if (pieces.at(i)->getPosition() == location && pieces.at(i)->getColor() != piece->getColor()){
            capt = pieces.at(i);
            break;
        }
    }

    if (capt != nullptr){
        captPos = capt->getPosition();
        capt->setPos(Coordinate{-1, -1});
    }

    piece->setPos(location);

    bool checkOrNot = isKingInCheck(piece->getColor(), pieces);

    piece->setPos(savPos);
    if (capt != nullptr){
        capt->setPos(captPos);
    }

    return !checkOrNot;
}

bool Check::isKingInCheck(Side col, const vector<Piece*> &pieces) const{
    Piece* kingInQuestion = (col == White) ? whiteKing : blackKing;
    Coordinate kingPos = kingInQuestion->getPosition();
    Side checkThis = (col == White) ? Black : White;

    //cout << "check color: " << checkThis << endl;

    for (unsigned i = 0; i < pieces.size(); i++){
        Piece* pp = pieces.at(i);
        Coordinate piecePos = pp->getPosition();
        string name = pp->getName();
        if (pp->getColor() == checkThis && !pp->isCaptured()){
            if (name == "Pawn" && checkDistance(piecePos, kingPos, 1.5)){
                bool killPositionX = ((piecePos.y + 1) == kingPos.y) || ((piecePos.y - 1) == kingPos.y);
                bool killPositionY = piecePos.x == kingPos.x + ((col == White) ?  1 : -1);
                //cout << "Coordinate: " << piecePos.x << ", " << piecePos.y << "- " << killPositionX << " " << killPositionY << endl;
                if (killPositionX && killPositionY){
                    return true;
                }
            }else if (name == "Rook" && (piecePos.x == kingPos.x || piecePos.y == kingPos.y)){
                if (canTakeKing(pieces, pp, kingInQuestion)){
                    return true;
                }
            }else if (name == "Bishop"){
                if (canTakeKing(pieces, pp, kingInQuestion)){
                    return true;
                }
            }else if (name == "Knight" && checkDistance(piecePos, kingPos, 3.0)){
                if (canTakeKing(pieces, pp, kingInQuestion)){
                    return true;
                }
            }else if (name == "Queen"){
                if (canTakeKing(pieces, pp, kingInQuestion)){
                    return true;
                }
            }else if (name == "King" && checkDistance(piecePos, kingPos, 1.5)){
                if (canTakeKing(pieces, pp, kingInQuestion)){
                    return true;
                }
            }
        }
    }

    return false;
}

bool Check::kingCanMove(Side col, const vector<Piece*> &pieces) const{
    Piece* kingInQuestion = (col == White) ? whiteKing : blackKing;
    Coordinate savPos = kingInQuestion->getPosition();

    vector<Coordinate> moves = kingInQuestion->possibleMoves(pieces);
    unsigned possibles = moves.size();
    for (unsigned i = 0; i < moves.size(); i++){
        if (!isLegalMove(pieces, kingInQuestion, moves.at(i))){
            possibles--;
        }
    }

    kingInQuestion->setPos(savPos);
    //cout << ((col == White) ? "White" : "Black") << possibles << endl;
    return possibles > 0;
}

bool Check::otherMoves(Side col, const vector<Piece*> &pieces) const{
    //cout << "check all pieces\n";
    for (unsigned i = 0; i < pieces.size(); i++){
        Piece* pp = pieces.at(i);
        if (pp->getColor() == col && !pp->isCaptured()){
            vector<Coordinate> moves = pp->possibleMoves(pieces);
            //cout << "check all moves\n";
            for (unsigned j = 0; j < moves.size(); j++){
                //cout << pp->getName()  <<"\n";
                if (isLegalMove(pieces, pp, moves.at(j))){
                    return true;
                }
            }
        }
    }

    return false;
}