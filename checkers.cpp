//
// Created by Bastien Taylor on 11/13/17.
//

#include "checkers.h"

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
Piece Board::getPieces(){

}

/*
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Draws the board with all pieces
 */
void Board::draw(){

}

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

}

//Getters
/*
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Gets the position of the piece
 */
point Piece::getPosition(){

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

}

/*
 * Requires: point Position
 * Modifies: Position of the piece
 * Effects: Moves the piece
 */
void Piece::movePiece(point p){

}

//Constructor
/*
 * Requires: Int for color and point for position
 * Modifies: color and position
 * Effects: Creates a piece with color c at point p
 */
BasicPiece::BasicPiece(int c, point p){

}

//Getters
/*
* Requires: Nothing
* Modifies: Nothing
* Effects: Returns int specifying color
*/
int BasicPiece::getColor(){

}

/*
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Returns the position of the piece
 */
point BasicPiece::getPosition(){

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

}

//Getters
/*
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Returns int specifying color
 */
int KingPiece::getColor(){

}

/*
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Returns the position of the piece
 */
point KingPiece::getPosition(){

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

}