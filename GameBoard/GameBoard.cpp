#include "GameBoard.hpp"

Game::Game(){
    turn = White;
    winner = Neutral;
    wTime = 180.0f;
    bTime = 180.0f;
    selectedPiece = nullptr;

    pieces.push_back(new King(Coordinate{5, 8}, White));
	pieces.push_back(new Queen(Coordinate{4, 8}, White));
	pieces.push_back(new Bishop(Coordinate{3, 8}, White));
	pieces.push_back(new Knight(Coordinate{2, 8}, White));
	pieces.push_back(new Rook(Coordinate{1, 8}, White));
	pieces.push_back(new Bishop(Coordinate{6, 8}, White));
	pieces.push_back(new Knight(Coordinate{7, 8}, White));
	pieces.push_back(new Rook(Coordinate{8, 8}, White));
    for (int i = 0; i < 8; i++){
        pieces.push_back(new Pawn(Coordinate{i+1, 7}, White));
    }

    pieces.push_back(new King(Coordinate{5, 1}, Black));
    pieces.push_back(new Queen(Coordinate{4, 1}, Black));
    pieces.push_back(new Bishop(Coordinate{3, 1}, Black));
    pieces.push_back(new Knight(Coordinate{2, 1}, Black));
    pieces.push_back(new Rook(Coordinate{1, 1}, Black));
    pieces.push_back(new Bishop(Coordinate{6, 1}, Black));
    pieces.push_back(new Knight(Coordinate{7, 1}, Black));
    pieces.push_back(new Rook(Coordinate{8, 1}, Black));
    for (int i = 0; i < 8; i++){
        pieces.push_back(new Pawn(Coordinate{i+1, 2}, Black));
    }

    checker = Check(pieces);
}

Game::~Game(){
    for (vector<Piece*>::iterator it = pieces.begin(); it != pieces.end(); it++){
        delete *it;
        *it = nullptr;
    }
}

vector<Coordinate> addCastlingMoves(Piece* selectedPiece, const vector<Piece*> &pieces, Piece* &relatedKing, Piece* &rightRook, Piece* &leftRook){
    vector<Coordinate> mvs;

    //Add Castling Moves
    if ((selectedPiece->getName() == "Rook" || selectedPiece->getName() == "King") && !selectedPiece->hasMoved()){
        Coordinate rSlide1, rSlide2;
        rSlide1.x = 6; rSlide2.x = 7;

        Coordinate lSlide1, lSlide2, lSlide3;
        lSlide1.x = 2; lSlide2.x = 3; lSlide3.x = 4;

        if (selectedPiece->getColor() == White){
            rSlide1.y = 8; rSlide2.y = 8;
            lSlide1.y = 8; lSlide2.y = 8; lSlide3.y = 8;
        }else{
            rSlide1.y = 1; rSlide2.y = 1;
            lSlide1.y = 1; lSlide2.y = 1; lSlide3.y = 1;
        }

        bool castleRight = true, castleLeft = true;
        for(unsigned i = 0; i < pieces.size(); i++){
            if (!castleRight && !castleLeft && relatedKing != nullptr && rightRook != nullptr && leftRook != nullptr){break;}
            Piece* pp = pieces.at(i);
            Coordinate pos = pp->getPosition();

            if (pos == lSlide1 || pos == lSlide2 || pos == lSlide3){
                castleLeft = false;
            }else if(pos == rSlide1 || pos == rSlide2){
                castleRight = false;
            }

            if (relatedKing == nullptr && pp->getName() == "King" && pp->getColor() == selectedPiece->getColor()){
                relatedKing = pp;
            }else if (pp->getName() == "Rook" && pp->getColor() == selectedPiece->getColor() && !pp->hasMoved()){
                rightRook = (pos.x == 8) ? pp : rightRook;
                leftRook = (pos.x == 1) ? pp : leftRook;
                //cout << "found the left rook? " << (leftRook != nullptr) << " or found the right rook? " << (rightRook != nullptr) << endl;
            }
        }
        
        //cout << castleLeft << " " << castleRight << endl;

        if (!relatedKing->hasMoved()){
            if (castleRight){
                if (relatedKing == selectedPiece && rightRook != nullptr){
                    mvs.push_back(Coordinate{7, lSlide1.y});
                }else if (rightRook == selectedPiece && relatedKing != nullptr){
                    mvs.push_back(Coordinate{6, lSlide1.y});
                }
            }

            if (castleLeft){
                if (relatedKing == selectedPiece && leftRook != nullptr){
                    mvs.push_back(Coordinate{3, lSlide1.y});
                }else if (leftRook == selectedPiece && relatedKing != nullptr){
                    mvs.push_back(Coordinate{4, lSlide1.y});
                }
            }
        }
    }

    //cout << (relatedKing != nullptr) << " " << (rightRook != nullptr) << " " << (leftRook != nullptr) << endl;
    return mvs;
}

void Game::select_move_piece(Coordinate location){
    //cout << location.x<< " , " << location.y << endl;
    if (selectedPiece == nullptr){
        for(size_t i=0; i<pieces.size(); i++){
            if(pieces.at(i)->getColor() == turn &&location.x==pieces.at(i)->getPosition().x&&location.y==pieces.at(i)->getPosition().y){
                selectedPiece = pieces.at(i);
                break;
            }
        }
        //check the vector by linear search to find matching location and matching turn

    }else{
        //we have a piece selected, so check that their move is legal
        bool possibleMove = false, castling = false;

        vector<Coordinate> moves = selectedPiece->possibleMoves(this->pieces);
        Piece* relatedKing = (selectedPiece->getName() == "King") ? selectedPiece : nullptr;
        Piece *rightRook = nullptr, *leftRook = nullptr;

        if (!wInCheck && !bInCheck){
            vector<Coordinate> castles = addCastlingMoves(selectedPiece, pieces, relatedKing, rightRook, leftRook);
        
            for (unsigned i = 0; i < castles.size(); i++){
                if(location == castles.at(i)){
                    possibleMove = true;
                    castling = true;
                    break;
                }
            }
        }
        
        if (!possibleMove){
            for(size_t i=0; i<moves.size(); i++){
                if(location.x==moves.at(i).x&&location.y==moves.at(i).y){
                    possibleMove = true;
                    break;
                }
            }
        }

        bool legality = checker.isLegalMove(pieces, selectedPiece, location);
        //cout << "Legal move? " << legality << endl;

        if (possibleMove && legality){ //if move is legal
            if (!castling){
                for(size_t i=0; i<pieces.size(); i++){
                    if(pieces.at(i)->getColor() != turn &&location.x==pieces.at(i)->getPosition().x&&location.y==pieces.at(i)->getPosition().y){
                        pieces.at(i)->capture();
                    }
                }
            }
            
            if (castling){
                bool left = location.x < 5;
                //cout << "Castling to the left? " << left << endl;

                if (selectedPiece == relatedKing){

                    if (left && leftRook != nullptr){
                        leftRook->move(Coordinate{4, location.y});
                    }else if (!left && rightRook != nullptr){
                        rightRook->move(Coordinate{6, location.y});

                    }
                }else{

                    if (left && relatedKing != nullptr){
                        relatedKing->move(Coordinate{3, location.y});
                    }else if (!left && relatedKing != nullptr){
                        relatedKing->move(Coordinate{7, location.y});
                    }

                }
            }
            selectedPiece->move(location);

            turn = (turn == White) ? Black : White;
        }

        bool promotionViable = selectedPiece->getPosition().y == 1 || selectedPiece->getPosition().y == 8;
        if (selectedPiece->getName() == "Pawn" && promotionViable){
            
            Piece *promotion = new Queen(selectedPiece->getPosition(), selectedPiece->getColor());
                
            for (unsigned i = 0; i < pieces.size(); i++){
                if (pieces.at(i) == selectedPiece){
                    pieces.erase(pieces.begin() + i);
                    
                    delete selectedPiece;
                    selectedPiece = nullptr;
                    
                    break;
                }
            }

            pieces.push_back(promotion);
        }

        selectedPiece = nullptr;
        check_win_condition();
    }
}     

void Game::decrementTimers(float frame_time){
    if (winner != Neutral || stalemate) {return;}

    if (turn == White) {
        wTime -= frame_time;
    }else{
        bTime -= frame_time;
    }

    if (wTime <= 0){
        winner = Black;
    }else if (bTime <= 0){
        winner = White;
    }
}

const vector<Piece*>& Game::get_pieces() const{
    return pieces;
}

const float Game::get_time(Side colr) const{
    return (colr == White) ? wTime : bTime;
}

Side Game::get_turn() const{
    return turn;
}

Piece* Game::get_selected_piece() const{
    return selectedPiece; 
}

void Game::check_win_condition(){
    if (winner != Neutral || stalemate) {return;}

    wInCheck = checker.isKingInCheck(White, pieces);
    bInCheck = checker.isKingInCheck(Black, pieces);
    //cout << "White In Check: " << wInCheck << ", Black In Check: " << bInCheck << endl;

    if (wTime <= 0){
        winner = Black;
    }else if (bTime <= 0){
        winner = White;
    }else{
        bool wKCanMove = checker.kingCanMove(White, pieces);
        bool bKCanMove = checker.kingCanMove(Black, pieces);

        bool wPCanMove = checker.otherMoves(White, pieces);
        bool bPCanMove = checker.otherMoves(Black, pieces);

        //cout << "WK Move: " << wKCanMove << ", WP Move: " << wPCanMove << ", BK Move: " << bKCanMove << ", BP Move: " << bPCanMove << endl;

        bool whiteCombo = (wKCanMove || wPCanMove);
        bool blackCombo = (bKCanMove || bPCanMove);

        if (!whiteCombo || !blackCombo){
            if (bInCheck && !blackCombo){ //check detector
                winner = White;
            }else if(wInCheck && !whiteCombo){ //check detector
                winner = Black;
            }else if ((!wInCheck && !whiteCombo && turn == White) || (!bInCheck && !blackCombo && turn == Black)){ //stalemate
                winner = Neutral;
                stalemate = true;
            }
        }
    }
}

Side Game::get_winner() const{
    return winner;
}

bool Game::get_stalemate() const{
    return stalemate;
}