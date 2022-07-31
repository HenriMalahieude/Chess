#ifndef __GAMBORD_
#define __GAMBORD_

#include "../globals.hpp"
#include "../Piece/Piece.hpp"
#include "../Check/Check.hpp"
#include <vector>

using namespace std;

class Game{
    private:
        vector<Piece*> pieces;

        Side winner;
        bool stalemate = false;

        Side turn;
        Piece *selectedPiece;

        bool wInCheck, bInCheck;
        float wTime, bTime;
        Check checker;
        
    public:
        Game(); //set it up here
        ~Game();
        
        void select_move_piece(Coordinate);
        void decrementTimers(float);

        const vector<Piece*>& get_pieces() const;
        const float get_time(Side) const; 
        Side get_turn() const;
        Piece* get_selected_piece() const;

        void check_win_condition();
        Side get_winner() const;
        bool get_stalemate() const;
};

#endif