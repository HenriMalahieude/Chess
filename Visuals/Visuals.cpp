#include "Visuals.hpp"
#include <string>

void drawBoard(){
	for (int x = 0; x < 8; x++){
		for (int y = 0; y < 8; y++){
			Color checker = GRAY;
			if ((x + (y % 2)) % 2 == 0) {
				checker = BROWN;
			}

			int xPos = x*squareSize + boardOffset;
			int yPos = y*squareSize + boardOffset;

			DrawRectangle(xPos, yPos, squareSize, squareSize, checker); //The Checker Box
			DrawRectangleLines(xPos, yPos, squareSize, squareSize, BLACK); //The Outline
		}
	}
}

void drawTimer(int sec1, int sec2){//, Texture2D &miniTexture){
	int min1 = sec1 / 60;
	int sec10 = sec1 - (min1 * 60);
	string p1Timer = "" + std::to_string(min1) + ":";
	if (sec10 < 10) {
		p1Timer += "0";
	}
	p1Timer += std::to_string(sec10);

	int min2 = sec2 / 60;
	int sec20 = sec2 - (min2 * 60);
	string p2Timer = "" + std::to_string(min2) + ":";
	if (sec20 < 10) {
		p2Timer += "0";
	}
	p2Timer += std::to_string(sec20);

	/*Rectangle wking = pieceSpriteLocations[WKing]; //sprite location
	wking.height /= 3;
	wking.width /= 3;
	wking.x /= 3;
	wking.y /= 3;

	Rectangle bking = pieceSpriteLocations[BKing]; //sprite location
	bking.height /= 3;
	bking.width /= 3;
	bking.x /= 3;
	bking.y /= 3;*/

	DrawText(p1Timer.c_str(), boardOffset, boardOffset + (squareSize*8), borderEmptySize/2, WHITE);
	//DrawTextureRec(miniTexture, wking, Vector2{boardOffset-miniSize, -1}, WHITE);
	
	DrawText(p2Timer.c_str(), boardOffset, boardOffset - (borderEmptySize/2), borderEmptySize/2, BLACK);
	//DrawTextureRec(miniTexture, bking, Vector2{boardOffset-miniSize, borderEmptySize/4}, WHITE);
}

void drawPieces(const vector<Piece*> &pieces, Texture2D &loadedSprite){
	//DrawTexture(loadedSprite, screenWidth/2 - loadedSprite.width/2, screenHeight/2 - loadedSprite.height/2, WHITE);
	//DrawTextureRec(loadedSprite, pieceSpriteLocations[BKing], Vector2{squareSize + boardOffset, squareSize + boardOffset}, WHITE);

	for (unsigned i = 0; i < pieces.size(); i++){
		Piece *curPiece = pieces.at(i);

		if (!curPiece->isCaptured()){
			Coordinate location = curPiece->getPosition();
			location.x -= 1;
			location.y -= 1;

			DrawTextureRec(loadedSprite, pieceSpriteLocations[curPiece->getPieceId()], Vector2{(float)squareSize*location.x + boardOffset, (float)squareSize*location.y + boardOffset}, WHITE);
		}
	}
}

void updateCaptured(const vector<Piece*> &pieces, Texture2D &loadedSprite){

	int white = 0;
	int black = 0;

	for (unsigned i = 0; i < pieces.size(); i++){
		Piece *curPiece = pieces.at(i);

		if (curPiece->isCaptured()){
			Rectangle sLoc = pieceSpriteLocations[curPiece->getPieceId()]; //sprite location
			sLoc.height /= 3;
			sLoc.width /= 3;
			sLoc.x /= 3;
			sLoc.y /= 3;

			Vector2 dLoc = Vector2{squareSize*8 + boardOffset, 0}; //Draw Location
			if (curPiece->getColor() == White){
				dLoc.x = boardOffset-sLoc.width;
				dLoc.y = boardOffset + (sLoc.height * white++);
			}else{
				dLoc.x = squareSize*8 + boardOffset;
				dLoc.y = squareSize*8 + boardOffset - (sLoc.height *  (1 + black++));
			}

			DrawTextureRec(loadedSprite, sLoc, dLoc, WHITE);
		}
	}	
}

Coordinate BoardGridFormat(int mX, int mY){
	clamp(mX, boardOffset, squareSize*7 + boardOffset);
	clamp(mY, boardOffset, squareSize*7 + boardOffset);

	Coordinate rr;
	rr.x = ((mX - (squareSize/2)) / squareSize) + 1;
	rr.y = ((mY - (squareSize/2)) / squareSize) + 1;

	return rr;
}