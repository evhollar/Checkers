//
// Created by Bastien Taylor on 11/13/17.
//

#include "checkers.h"

/*
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Saves the game
 */
void Menu::saveGame(){
    
}

/*
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Loads the game
 */
void Menu::loadGame(){

}

/*
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Exits the game
 */
void Menu::exitGame(){

}

/*
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Restarts the game
 */
void Menu::restartGame(){

}

//Constructor
/*
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Creates a piece
 */
Piece::Piece(){
    color = 1;
    position = {0,0};
}

//Getters
/*
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Gets the position of the piece
 */
point Piece::getPosition(){
    return position;
}

/*
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Captures the piece
 */
void Piece::capture(){

}

/*
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Returns an int specifying color of the piece
 */
int Piece::getColor(){
    return color;
}

//Constructor
/*
 * Requires: Int for color and point for position
 * Modifies: color and position
 * Effects: Creates a piece with color c at point p
 */
BasicPiece::BasicPiece(int c, point p){
    color = c;
    position = p;
}

/*
 * Requires: point position
 * Modifies: Position
 * Effects: Moves the piece to position p
 */
void BasicPiece::movePiece(point p) {
    position = p;
}

/*
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Makes the BasicPiece a KingPiece
 */
void BasicPiece::upgradePiece(){

}

//Constructor
/*
* Requires: Int for color and point for position
* Modifies: color and position
* Effects: Creates a piece with color c at point p
*/
KingPiece::KingPiece(int c, point p){
    color = c;
    position = p;
}

/*
 * Requires: point position
 * Modifies: Position
 * Effects: Moves the piece to position p
 */
void KingPiece::movePiece(point p) {
    position = p;
}

// Constructors
/*
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Creates a Board object
 */
Board::Board(){

}

//Getters
/*
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Return all pieces
 */
vector<BasicPiece> Board::getRedBasicPieces(){
    return redBasicPieces;
}

/*
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Return all pieces
 */
vector<KingPiece> Board::getRedKingPieces(){
    return redKingPieces;
}

/*
* Requires: Nothing
* Modifies: Nothing
* Effects: Return all pieces
*/
vector<BasicPiece> Board::getBlackBasicPieces(){
    return blackBasicPieces;
}

/*
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Return all pieces
 */
vector<KingPiece> Board::getBlackKingPieces(){
    return blackKingPieces;
}

/*
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Draws the board with all pieces
 */
void Board::draw(){

}