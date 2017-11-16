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

EmptyPiece::EmptyPiece(point p) : Piece() {
    position = p;
    type = "empty";
}

string EmptyPiece::getType() const {
    return "empty";
}

void EmptyPiece::movePiece(point p) {
    position = p;
}

// Constructors
/*
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Creates a Board object
 */
Board::Board(){

    //Cycle through all the columns
    for ( int c = 0; c < 8 ; ++c)
    {
        //Creates a vector of pieces for each column of the board
        vector<unique_ptr<Piece>> col;

        //Adds an empty piece to each spot in the vector
        for ( int r = 0; r < 8 ; ++r)
        {
            col.push_back(unique_ptr<Piece>(new EmptyPiece({c, r})));
        }

        //Adds the column vector to the vector of columns, aka the board.
        pieces.push_back(move(col));
    }
}

/*
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Draws the board with all pieces
 */
void Board::draw(){

}

void Board::capturePiece(int x, int y) {
    pieces[x][y] = make_unique<EmptyPiece>(EmptyPiece({x, y}));
}

void Board::movePiece(int x1, int y1, int x2, int y2) {
    if (pieces[x1][y1]->getType() == "basic"){
        pieces[x2][y2] = make_unique<BasicPiece>(BasicPiece(pieces[x1][y1]->getColor(), {x2, y2}));
    }
    if (pieces[x1][y1]->getType() == "king"){
        pieces[x2][y2] = make_unique<KingPiece>(KingPiece(pieces[x1][y1]->getColor(), {x2, y2}));
    }
    pieces[x1][y1] =  make_unique<EmptyPiece>(EmptyPiece({x1, y1}));
}

/*
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Saves the game by storing the positions, types, and colors of all pieces on the board.
 */
void Menu::saveGame(const vector<vector<unique_ptr<Piece>>> &pieces) {
    ofstream f_out("checkersSaveData.txt", ios::app);
    if (f_out) {
        for (int c = 0; c < pieces.size(); c++) {
            for (int r = 0; r < pieces.size(); r++) {
                f_out << pieces[c][r]->getType() << endl;
                f_out << pieces[c][r]->getPosition().x << endl;
                f_out << pieces[c][r]->getPosition().y << endl;
                f_out << pieces[c][r]->getColor() << endl;
            }
        }
        f_out.close();
    }
}

/*
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Loads the game. Currently DOES NOT WORK
 */
void Menu::loadGame(string fileName, vector<vector<unique_ptr<Piece>>> &pieces){
    ifstream f_in(fileName);
    if (f_in){
        string word = "";
        int tempX;
        int tempY;
        int tempColor;
        f_in >> word;
        if(word == "empty") {
            f_in >> tempX;
            f_in >> tempY;
            f_in >> tempColor;
            pieces[tempX][tempY] = make_unique<EmptyPiece>(EmptyPiece({tempX, tempY}));
        } if(word == "basic"){
            f_in >> tempX;
            f_in >> tempY;
            f_in >> tempColor;
            pieces[tempX][tempY] = make_unique<BasicPiece>(BasicPiece(tempColor, {tempX, tempY}));
        } if (word == "king"){
            f_in >> tempX;
            f_in >> tempY;
            f_in >> tempColor;
            pieces[tempX][tempY] = make_unique<KingPiece>(KingPiece(tempColor, {tempX, tempY}));

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