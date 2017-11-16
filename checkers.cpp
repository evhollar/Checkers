//
// Created by Bastien Taylor on 11/13/17.
//

#include "checkers.h"

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

string Piece::getType() {
    return type;
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
    type = "basic";
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
    type = "king";
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

/*
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Saves the game
 */
void Menu::saveGame(vector<BasicPiece> rbp, vector<BasicPiece> bbp, vector<KingPiece> rkp, vector<KingPiece> bkp){
    ofstream f_out("checkersSaveData.txt", ios::app);
    if (f_out){
        for(int i = 0; i < rbp.size(); i++){
            f_out << rbp[i].getType() << endl;
            f_out << rbp[i].getPosition().x << endl;
            f_out << rbp[i].getPosition().y << endl;
            f_out << rbp[i].getColor() << endl;
        }
        for(int i = 0; i < bbp.size(); i++){
            f_out << bbp[i].getType() << endl;
            f_out << bbp[i].getPosition().x << endl;
            f_out << bbp[i].getPosition().y << endl;
            f_out << bbp[i].getColor() << endl;
        }
        for(int i = 0; i < rkp.size(); i++){
            f_out << rkp[i].getType() << endl;
            f_out << rkp[i].getPosition().x << endl;
            f_out << rkp[i].getPosition().y << endl;
            f_out << rkp[i].getColor() << endl;
        }
        for(int i = 0; i < bkp.size(); i++){
            f_out << bkp[i].getType() << endl;
            f_out << bkp[i].getPosition().x << endl;
            f_out << bkp[i].getPosition().y << endl;
            f_out << bkp[i].getColor() << endl;
        }
    }
    f_out.close();
}

/*
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Loads the game
 */
void Menu::loadGame(string fileName){
    ifstream f_in(fileName);
    if (f_in){
        string word = "";
        int tempX;
        int tempY;
        int tempColor;
        f_in >> word;
        if(word == "basic"){
            f_in >> tempX;
            f_in >> tempY;
            f_in >> tempColor;
            BasicPiece tempBasic = BasicPiece(tempColor, {tempX, tempY});
            if(tempColor == 0){
                
            }
        }

    }

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