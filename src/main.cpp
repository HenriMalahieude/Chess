#include <iostream>
#include "Visuals/Visuals.hpp"
#include "GameBoard/GameBoard.hpp"

int main(){
    // Initialization
    //--------------------------------------------------------------------------------------
    int mouseX = 0;
    int mouseY = 0;

    Game gm;

    InitWindow(screenWidth, screenHeight, "Dream Team's Chess");

    Image piecesPNG = LoadImage("resources/sprite.png");
    Image capturedPNG = ImageCopy(piecesPNG);

    ImageResize(&piecesPNG, squareSize*6, squareSize*2); //to fit the board
    ImageResize(&capturedPNG, miniSize*6, miniSize*2);

	Texture2D piecesSprite = LoadTextureFromImage(piecesPNG);
    Texture2D capturedSprite = LoadTextureFromImage(capturedPNG);

    UnloadImage(capturedPNG); //no longer needed
    UnloadImage(piecesPNG);

    SetTargetFPS(30);// Set our game to run at 60 frames-per-second
    ShowCursor();

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        //Inputs
        //----------------------------------------------------------------------------------
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && gm.get_winner() == Neutral && !gm.get_stalemate()){
            mouseX = GetMouseX();
            mouseY = GetMouseY();

            Coordinate gridded = BoardGridFormat(mouseX, mouseY);
            gm.select_move_piece(gridded);
            //std::cout << "( " << mouseX << ", " << mouseY << " ) ; ( " << gridded.x << ", " << gridded.y << " )\n";
        }

        // Update
        //----------------------------------------------------------------------------------
        //cout << gm.get_stalemate() << " : " << gm.get_winner() << endl;
        gm.decrementTimers(GetFrameTime());

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(DARKGRAY);

            drawBoard();
            drawTimer(gm.get_time(White), gm.get_time(Black));//, capturedSprite);

            if (gm.get_selected_piece() != nullptr){
                Coordinate pos = gm.get_selected_piece()->getPosition();
                DrawRectangle((pos.x-1)*squareSize + boardOffset, (pos.y-1)*squareSize + boardOffset, squareSize, squareSize, Color{0, 255, 0, 100});
            }

            drawPieces(gm.get_pieces(), piecesSprite);
            updateCaptured(gm.get_pieces(), capturedSprite);

            if (gm.get_winner() != Neutral || gm.get_stalemate()){
                if (!gm.get_stalemate()){
                    string text = (gm.get_winner() == White) ? ("White") : ("Black");
                    DrawText((text + " wins!").c_str(), (screenWidth/2) - 160, screenHeight / 2, 50, RED);
                }else{
                    DrawText("Stalemate!", (screenWidth/2) - 24, screenHeight / 2, 50, RED);
                }
            }
        EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(piecesSprite);
    UnloadTexture(capturedSprite);
    CloseWindow();// Close window and OpenGL context

    return 0;
}