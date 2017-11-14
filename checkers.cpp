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

/*
 * Requires: point Position
 * Modifies: Position of the piece
 * Effects: Moves the piece
 */
void Piece::movePiece(point p){
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
 * Effects: Return all red pieces
 */
vector<Piece> Board::getRedPieces(){
    return redPieces;
}

/*
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Return all black pieces
 */
vector<Piece> Board::getBlackPieces(){
    return blackPieces;
}

/*
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Draws the board with all pieces
 */
void Board::draw(){

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

//Getters
/*
* Requires: Nothing
* Modifies: Nothing
* Effects: Returns int specifying color
*/
int BasicPiece::getColor(){
    return color;
}

/*
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Returns the position of the piece
 */
point BasicPiece::getPosition(){
    return position;
}

/*
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Captures the piece
 */
void BasicPiece::capture(){

}

/*
 * Requires: point position
 * Modifies: Position
 * Effects: Moves the piece to position p
 */
void BasicPiece::movePiece(point p){
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

//Getters
/*
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Returns int specifying color
 */
int KingPiece::getColor(){
    return color;
}

/*
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Returns the position of the piece
 */
point KingPiece::getPosition(){
    return position;
}

/*
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Captures the piece
 */
void KingPiece::capture(){

}

/*
 * Requires: point position
 * Modifies: Position
 * Effects: Moves the piece to position p
 */
void KingPiece::movePiece(point p){
    position = p;
}