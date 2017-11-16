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

void Piece::draw(){
    cout << getType() << " piece is located at ("
         << getPosition().x << "," << getPosition().y << ")" << endl;
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

/*
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Returns the type of the piece
 */
string BasicPiece::getType() const {
    return "basic";
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

/*
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Returns the type of the piece
 */
string KingPiece::getType() const {
    return "king";
}

// Constructors
/*
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Creates a Board object
 */
Board::Board(){
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
 * Effects: Saves the game by storing the positions, types, and colors of all pieces on the board.
 */
void Menu::saveGame(const vector<unique_ptr<Piece>> &pieces) {
    ofstream f_out("checkersSaveData.txt", ios::app);
    if (f_out) {
        for (int i = 0; i < pieces.size(); i++) {
            f_out << pieces[i]->getType() << endl;
            f_out << pieces[i]->getPosition().x << endl;
            f_out << pieces[i]->getPosition().y << endl;
            f_out << pieces[i]->getColor() << endl;
        }
        f_out.close();
    }
}

/*
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Loads the game. Currently DOES NOT WORK
 */
void Menu::loadGame(string fileName, vector<unique_ptr<Piece>> pieces){
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
            pieces.push_back(make_unique<BasicPiece>(tempBasic));
        } if (word == "king"){
            f_in >> tempX;
            f_in >> tempY;
            f_in >> tempColor;
            KingPiece tempKing = KingPiece(tempColor, {tempX, tempY});
                pieces.push_back(make_unique<KingPiece>(tempKing));

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
void Menu::restartGame(){}