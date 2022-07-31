#include "Piece.hpp"
#include <iostream>
#include <vector>
#include "raylib.h"

using namespace std;

bool check_board_please(const vector<Piece*> &board, Coordinate pos, Side pieceColor, vector<Coordinate> &moves){
    for (unsigned i = 0; i < board.size(); i++){ //check that there isn't anything interefering with the "slide"
        Piece *pp = board.at(i);
        if (pp->getPosition() == pos){
            if (pp->getColor() != pieceColor){
                moves.push_back(pos); //The piece infront of us is an enemy! Add it to possible moves due to captures.
            }
            return true;
        }
    }

    return false;
}

Piece::Piece(){
    this->position.x=0;
    this->position.y=0;
    this->name="Piece";
    this->color=White;
    this->pid=WKing;
    this->captured=false;
    this->moved = false;
}

Piece::Piece(Coordinate p, string n, Side c, PieceSpriteId id){
    this->position=p;
    this->name=n;
    this->color=c;
    this->pid=id;
    this->captured=false;
    this->moved = false;
}

Piece::~Piece(){
    
}

string Piece::getName() const{
    return this->name;
}

Coordinate Piece::getPosition() const{
    return this->position;
}

void Piece::move(Coordinate p){
    this->moved = true;
    setPos(p);
}

void Piece::setPos(Coordinate p){
    this->position = p;
}

PieceSpriteId Piece::getPieceId() const{
    return this->pid;
}

Side Piece::getColor() const{
    return this->color;
}

bool Piece::isCaptured() const{
    return this->captured;
}

void Piece::capture(){
    position.x = -1;
    position.y = -1;

    captured = true;
}

bool Piece::hasMoved() const{
    return moved;
}

//Queen
vector<Coordinate> Queen::possibleMoves(const vector<Piece*> &chessboard){
    vector<Coordinate> spots;
    Coordinate cur = this->position;

    //Up
    for (int y = (cur.y-1); y > 0; y--){ //go through each possible position starting at one above the current position
        Coordinate possible = Coordinate{cur.x, y};
        bool end = check_board_please(chessboard, possible, this->color, spots);

        if (end){
            break;
        }

        spots.push_back(possible);
    }

    //Down
    for (int y = (cur.y+1); y < 9; y++){
        Coordinate possible = Coordinate{cur.x, y};
        bool end = check_board_please(chessboard, possible, this->color, spots);

        if (end){
            break;
        }

        spots.push_back(possible);
    }

    //Left
    for (int x = (cur.x-1); x > 0; x--){
        Coordinate possible = Coordinate{x, cur.y};
        bool end = check_board_please(chessboard, possible, this->color, spots);

        if (end){
            break;
        }

        spots.push_back(possible);
    }

    //Right
    for (int x = (cur.x+1); x < 9; x++){
        Coordinate possible = Coordinate{x, cur.y};
        bool end = check_board_please(chessboard, possible, this->color, spots);

        if (end){
            break;
        }

        spots.push_back(possible);
    }

    //Left Up
    Coordinate diagonal = cur;
    diagonal.x += -1;
    diagonal.y += -1;
    while (diagonal.x > 0 && diagonal.x < 9 && diagonal.y > 0 && diagonal.y < 9){
        bool end = check_board_please(chessboard, diagonal, this->color, spots);

        if (end){
            break;
        }

        spots.push_back(diagonal);
        diagonal.x += -1;
        diagonal.y += -1;
    }

    //Right Up
    diagonal = cur;
    diagonal.x += 1;
    diagonal.y += -1;
    while (diagonal.x > 0 && diagonal.x < 9 && diagonal.y > 0 && diagonal.y < 9){
        bool end = check_board_please(chessboard, diagonal, this->color, spots);

        if (end){
            break;
        }

        spots.push_back(diagonal);
        diagonal.x += 1;
        diagonal.y += -1;
    }

    //Left Down
    diagonal = cur;
    diagonal.x += -1;
    diagonal.y += 1;
    while (diagonal.x > 0 && diagonal.x < 9 && diagonal.y > 0 && diagonal.y < 9){
        bool end = check_board_please(chessboard, diagonal, this->color, spots);

        if (end){
            break;
        }

        spots.push_back(diagonal);
        diagonal.x += -1;
        diagonal.y += 1;
    }
    

    //Right Down
    diagonal = cur;
    diagonal.x += 1;
    diagonal.y += 1;
    while (diagonal.x > 0 && diagonal.x < 9 && diagonal.y > 0 && diagonal.y < 9){
        bool end = check_board_please(chessboard, diagonal, this->color, spots);

        if (end){
            break;
        }

        spots.push_back(diagonal);
        diagonal.x += 1;
        diagonal.y += 1;
    }

    return spots;
}

//King
vector<Coordinate> King::possibleMoves(const vector<Piece*> &chessboard){
    Coordinate cur=this->getPosition();
    int tempx=cur.x;
    int tempy=cur.y;
    vector<Coordinate> spots;

    //left
    if(tempx>1){
        Coordinate possible{tempx-1, tempy};

        if (!check_board_please(chessboard, possible, this->color, spots)){
            spots.push_back(possible);
        }
    }

    //right
    if(tempx<8){
        Coordinate possible{tempx+1, tempy};

        if (!check_board_please(chessboard, possible, this->color, spots)){
            spots.push_back(possible);
        }
    }

    //down
    if(tempy<8){
        Coordinate possible{tempx, tempy+1};

        if (!check_board_please(chessboard, possible, this->color, spots)){
            spots.push_back(possible);
        }
    }

    //up
    if(tempy>1){
        Coordinate possible{tempx, tempy-1};

        if (!check_board_please(chessboard, possible, this->color, spots)){
            spots.push_back(possible);
        }
    }

    //leftup
    if(tempx>1 && tempy>1){
        Coordinate possible{tempx-1, tempy-1};

        if (!check_board_please(chessboard, possible, this->color, spots)){
            spots.push_back(possible);
        }
    }

    //leftdown
    if(tempx>1 && tempy<8){
        Coordinate possible{tempx-1, tempy+1};

        if (!check_board_please(chessboard, possible, this->color, spots)){
            spots.push_back(possible);
        }
    }

    //rightup
    if(tempx<8 && tempy>1){
        Coordinate possible{tempx+1, tempy-1};

        if (!check_board_please(chessboard, possible, this->color, spots)){
            spots.push_back(possible);
        }
    }

    //rightdown
    if(tempx<8 && tempy<8){
        Coordinate possible{tempx+1, tempy+1};

        if (!check_board_please(chessboard, possible, this->color, spots)){
            spots.push_back(possible);
        }
    }

    return spots;
}

vector<Coordinate> Bishop::possibleMoves(const vector<Piece*> &chessboard){
    Coordinate cur = this->position;
    vector<Coordinate> spots;

    //Left Up
    Coordinate diagonal = cur;
    diagonal.x += -1;
    diagonal.y += -1;
    while (diagonal.x > 0 && diagonal.x < 9 && diagonal.y > 0 && diagonal.y < 9){
        bool end = check_board_please(chessboard, diagonal, this->color, spots);

        if (end){
            break;
        }

        spots.push_back(diagonal);
        diagonal.x += -1;
        diagonal.y += -1;
    }

    //Right Up
    diagonal = cur;
    diagonal.x += 1;
    diagonal.y += -1;
    while (diagonal.x > 0 && diagonal.x < 9 && diagonal.y > 0 && diagonal.y < 9){
        bool end = check_board_please(chessboard, diagonal, this->color, spots);

        if (end){
            break;
        }

        spots.push_back(diagonal);
        diagonal.x += 1;
        diagonal.y += -1;
    }

    //Left Down
    diagonal = cur;
    diagonal.x += -1;
    diagonal.y += 1;
    while (diagonal.x > 0 && diagonal.x < 9 && diagonal.y > 0 && diagonal.y < 9){
        bool end = check_board_please(chessboard, diagonal, this->color, spots);

        if (end){
            break;
        }

        spots.push_back(diagonal);
        diagonal.x += -1;
        diagonal.y += 1;
    }
    

    //Right Down
    diagonal = cur;
    diagonal.x += 1;
    diagonal.y += 1;
    while (diagonal.x > 0 && diagonal.x < 9 && diagonal.y > 0 && diagonal.y < 9){
        bool end = check_board_please(chessboard, diagonal, this->color, spots);

        if (end){
            break;
        }

        spots.push_back(diagonal);
        diagonal.x += 1;
        diagonal.y += 1;
    }

    return spots;
}

vector<Coordinate> Rook::possibleMoves(const vector<Piece*> &chessboard){
    vector<Coordinate> spots;
    Coordinate cur = this->position;

    //Up
    for (int y = (cur.y-1); y > 0; y--){ //go through each possible position starting at one above the current position
        Coordinate possible = Coordinate{cur.x, y};
        bool end = check_board_please(chessboard, possible, this->color, spots);

        if (end){
            break;
        }

        spots.push_back(possible);
    }

    //Down
    for (int y = (cur.y+1); y < 9; y++){
        Coordinate possible = Coordinate{cur.x, y};
        bool end = check_board_please(chessboard, possible, this->color, spots);

        if (end){
            break;
        }

        spots.push_back(possible);
    }

    //Left
    for (int x = (cur.x-1); x > 0; x--){
        Coordinate possible = Coordinate{x, cur.y};
        bool end = check_board_please(chessboard, possible, this->color, spots);

        if (end){
            break;
        }

        spots.push_back(possible);
    }

    //Right
    for (int x = (cur.x+1); x < 9; x++){
        Coordinate possible = Coordinate{x, cur.y};
        bool end = check_board_please(chessboard, possible, this->color, spots);

        if (end){
            break;
        }

        spots.push_back(possible);
    }

    return spots;
}

vector<Coordinate> Pawn::possibleMoves(const vector<Piece*> &chessboard){
    Coordinate possible, dpos, attack1, attack2;
    Coordinate cur = this->position;
    vector<Coordinate> spots;

    //Set up constants among possible moves
    possible = cur;
    dpos.x = cur.x;
    attack1 = Coordinate{cur.x-1, 0};
    attack2 = Coordinate{cur.x+1, 0};

    //Set up the changing things for each side
    if (this->color == White){
        possible = Coordinate{cur.x, cur.y-1};
        dpos.y = cur.y-2;
        attack1.y = cur.y-1;
        attack2.y = cur.y-1;
    }else{
        possible = Coordinate{cur.x, cur.y+1};
        dpos.y = cur.y+2;
        attack1.y = cur.y+1;
        attack2.y = cur.y+1;
    }

    //Check that we can move
    bool addStraight = true;
    bool addDoubleStraight = (this->color == White) ? (cur.y == 7) : (cur.y == 2);
    //cout << addDoubleStraight << endl;
    bool addAtt1 = false;
    bool addAtt2 = false;

    //The actual check
    for (unsigned i = 0; i < chessboard.size(); i++){
        Piece* pp = chessboard.at(i);
        if (addStraight){ //Straight check
            if (pp->getPosition() == possible){
                addStraight = false;
            }else if (pp->getPosition() == dpos){
                addDoubleStraight = false;
            }
        }
        
        //Attack check (diagonal fronts)
        if (pp->getPosition() == attack1){
            addAtt1 = true;
        }else if (pp->getPosition() == attack2){
            addAtt2 = true;
        }
    }

    //Add them finally
    if (addStraight && possible.y > 1 && possible.y < 8){
        spots.push_back(possible);

        if (addDoubleStraight){
            spots.push_back(dpos);
        }
    }

    if (addAtt1){
        spots.push_back(attack1);
    }

    if (addAtt2){
        spots.push_back(attack2);
    }

    return spots;
}

vector<Coordinate> Knight::possibleMoves(const vector<Piece*> &chessboard){
    Coordinate cur = this->getPosition();
    vector<Coordinate> spots;

    //left down
    if(cur.x > 2 && cur.y < 8){
        Coordinate possible{cur.x-2, cur.y+1};

        if (!check_board_please(chessboard, possible, this->color, spots)){
            spots.push_back(possible);
        }
    }

    //left up
    if(cur.x > 2 && cur.y > 1){
        Coordinate possible{cur.x-2, cur.y-1};

        if (!check_board_please(chessboard, possible, this->color, spots)){
            spots.push_back(possible);
        }
    }

    //right down
    if(cur.x < 7 && cur.y < 8){
        Coordinate possible{cur.x+2, cur.y+1};

        if (!check_board_please(chessboard, possible, this->color, spots)){
            spots.push_back(possible);
        }
    }

    //right up
    if(cur.x < 7 && cur.y > 1){
        Coordinate possible{cur.x+2, cur.y-1};

        if (!check_board_please(chessboard, possible, this->color, spots)){
            spots.push_back(possible);
        }
    }

    //up right
    if(cur.x < 8 && cur.y > 2){
        Coordinate possible{cur.x+1, cur.y-2};

        if (!check_board_please(chessboard, possible, this->color, spots)){
            spots.push_back(possible);
        }
    }

    //up left
    if(cur.x > 1 && cur.y > 2){
        Coordinate possible{cur.x-1, cur.y-2};

        if (!check_board_please(chessboard, possible, this->color, spots)){
            spots.push_back(possible);
        }
    }

    //down right
    if(cur.x < 8 && cur.y < 7){
        Coordinate possible{cur.x+1, cur.y+2};

        if (!check_board_please(chessboard, possible, this->color, spots)){
            spots.push_back(possible);
        }
    }

    //down left
    if(cur.x > 1 && cur.y < 7){
        Coordinate possible{cur.x-1, cur.y+2};

        if (!check_board_please(chessboard, possible, this->color, spots)){
            spots.push_back(possible);
        }
    }

    return spots;
}