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
 * Effects: Returns an int specifying color of the piece
 */
int Piece::getColor(){
    return color;
}

/*
 * Requires: nothing
 * Modifies: nothing
 * Effects: draws the piece
 */
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
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Returns the type of the piece
 */
string BasicPiece::getType() const {
    return type;
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
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Returns the type of the piece
 */
string KingPiece::getType() const {
    return type;
}

/*
 * Requires: point position
 * Modifies: nothing
 * Effects: creates an EmptyPiece object at position p
 */
EmptyPiece::EmptyPiece(point p) : Piece() {
    position = p;
    color = 2;
    type = "empty";
}

/*
 * Requires: nothing
 * Modifies: nothing
 * Effects: returns type of EmptyPiece
 */
string EmptyPiece::getType() const {
    return "empty";
}

// Constructors
/*
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Creates a Board object
 */
Board::Board(){

    //Sets up a new board
    //Cycle through all the columns
    for ( int c = 0; c < size ; ++c)
    {
        //Creates a vector of pieces for each column of the board
        vector<unique_ptr<Piece>> col;

        //Adds basic or empty pieces to the board depending on the position.
        for (int r = 0; r < size ; ++r) {
            if ((c % 2 != r % 2) && r < 3) {
                col.push_back(unique_ptr<Piece>(new BasicPiece(0, {c, r})));
            } else if ((c % 2 != r % 2) && r > size - 4) {
                col.push_back(unique_ptr<Piece>(new BasicPiece(1, {c, r})));
            } else {
                col.push_back(unique_ptr<Piece>(new EmptyPiece({c, r})));
            }
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

/*
 * Requires: int x and int y
 * Modifies: pieces vector
 * Effects: Removes piece at x, y and replaces it with an empty piece
 */
void Board::capturePiece(int x, int y) {
    pieces[x][y] = make_unique<EmptyPiece>(EmptyPiece({x, y}));
}

/*
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Makes the BasicPiece a KingPiece
 */
void Board::upgradePiece(int x, int y){
    pieces[x][y] = make_unique<KingPiece>(KingPiece(pieces[x][y]->getColor(), {x, y}));
}

/*
 * Requires: int x1, int x2, int y1, int y2
 * Modifies: pieces vector
 * Effects: Moves the piece at location x1, y1 to location x2, y2
 */

void Board::movePiece(int x1, int y1, int x2, int y2) {

    //BLUE BASIC
    if (pieces[x1][y1]->getColor() == 0 && pieces[x1][y1]->getType() == "basic" && turn == 0) {
        //BLUE BASIC MOVE
        //and the clicked spot is a spot where the blue piece can move
        //Can't make a basic move if it is your turn for a bonus move
        if ((x2 == x1 + 1 || x2 == x1 - 1) && y2 == y1 + 1 && bonusMove == 0) {
            //Move the blue active piece there and set it to red's turn
            pieces[x2][y2] = make_unique<BasicPiece>(BasicPiece(pieces[x1][y1]->getColor(), {x2, y2}));
            capturePiece(x1, y1);
            bonusMove = 0;
            turn = 1;
        }
        //BLUE BASIC CAPTURE
        //If the clicked spot is over a red piece and it's red's turn
        if ((x2 == x1 + 2 || x2 == x1 - 2) && y2 == y1 + 2
            && pieces[(x1 + x2) / 2][(y1 + y2) / 2]->getColor() == 1) {
            //Move the blue piece there and capture the red piece
            pieces[x2][y2] = make_unique<BasicPiece>(BasicPiece(0, {x2, y2}));
            capturePiece(x1, y1);
            capturePiece((x1 + x2) / 2, (y1 + y2) / 2);
            turn = 1;
            bonusMove = 0;
            //If the piece is moved to a central spot on the board
            if (y2 < size - 2 && x2 > 1 && x2 < size - 2) {
                //Check all possible spots for a bonus capture
                if ((pieces[x2 - 2][y2 + 2]->getType() == "empty" && pieces[x2 - 1][y2 + 1]->getColor() == 1)
                    || (pieces[x2 + 2][y2 + 2]->getType() == "empty" && pieces[x2 + 1][y2 + 1]->getColor() == 1)) {
                    //If there is a bonus capture available set the active piece to the current piece and the
                    //turn back to blue's turn
                    bonusMove = 1;
                    activePiece = {x2, y2};
                    turn = 0;
                }
            }
            //If it's moved to a spot on the left of the board, only check the spots to the right.
            //Can't check spots outside the range of the board - will cause a crash
            if (y2 < size - 2 && x2 < 2) {
                if (pieces[x2 + 2][y2 + 2]->getType() == "empty" && pieces[x2 + 1][y2 + 1]->getColor() == 1) {
                    //If there is a bonus capture available set the active piece to the current piece and the
                    //turn back to blue's turn
                    bonusMove = 1;
                    activePiece = {x2, y2};
                    turn = 0;
                }
            }
            if (y2 < size - 2 && x2 > size - 3) {
                if (pieces[x2 - 2][y2 + 2]->getType() == "empty" && pieces[x2 - 1][y2 + 1]->getColor() == 1) {
                    //If there is a bonus capture available set the active piece to the current piece and the
                    //turn back to red's turn
                    bonusMove = 1;
                    activePiece = {x2, y2};
                    turn = 0;
                }
            }
        }
    }
    //BLUE UPGRADE
    if (y2 == size - 1 && pieces[x2][y2]->getType() == "basic" && pieces[x2][y2]->getColor() == 0) {
        upgradePiece(x2, y2);
        //If the piece was upgraded on a capture move and there is another capture move available
        if (y1 == size - 3 && x2 > 2 && x2 < size - 2 &&
            ((pieces[x2 - 2][y2 - 2]->getType() == "empty" && pieces[x2 - 1][y2 - 1]->getColor() == 1)
             || (pieces[x2 + 2][y2 - 2]->getType() == "empty" && pieces[x2 + 1][y2 - 1]->getColor() == 1))) {
            bonusMove = 1;
            activePiece = {x2, y2};
            turn = 0;
        }
    }
    //RED BASIC
    //If the active piece is a red piece
    if (pieces[x1][y1]->getColor() == 1 && pieces[x1][y1]->getType() == "basic" && turn == 1) {
        //and the clicked spot is a spot where the red piece can move
        //Can't make a basic move if it is your turn for a bonus move
        if ((x2 == x1 + 1 || x2 == x1 - 1) && y2 == y1 - 1 && bonusMove == 0) {
            //Move the red active piece there and set it to blue's turn
            pieces[x2][y2] = make_unique<BasicPiece>(BasicPiece(1, {x2, y2}));
            capturePiece(x1, y1);
            turn = 0;
        }
        //RED BASIC CAPTURE
        //If the clicked spot is over a blue piece
        if ((x2 == x1 + 2 || x2 == x1 - 2) && y2 == y1 - 2
            && pieces[(x1 + x2) / 2][(y1 + y2) / 2]->getColor() == 0) {
            //Move the red piece there and capture the blue piece
            pieces[x2][y2] = make_unique<BasicPiece>(BasicPiece(pieces[x1][y1]->getColor(), {x2, y2}));
            capturePiece(x1, y1);
            capturePiece((x1 + x2) / 2, (y1 + y2) / 2);
            //Set it to blue's turn and note no bonus move available.
            turn = 0;
            bonusMove = 0;
            //If the piece is moved to a central spot on the board
            if (y2 > 1 && x2 > 1 && x2 < size - 2) {
                //Check all possible spots for a bonus capture
                if ((pieces[x2 - 2][y2 - 2]->getType() == "empty" && pieces[x2 - 1][y2 - 1]->getColor() == 0)
                    || (pieces[x2 + 2][y2 - 2]->getType() == "empty" && pieces[x2 + 1][y2 - 1]->getColor() == 0)) {
                    //If there is a bonus capture available set the active piece to the current piece and the
                    //turn back to red's turn. Can only move that piece.
                    bonusMove = 1;
                    activePiece = {x2, y2};
                    turn = 1;
                }
            }
            //If it's moved to a spot on the left side of the board, only check the spots to the right to avoid crash
            if (y2 > 1 && x2 < 2) {
                if (pieces[x2 + 2][y2 - 2]->getType() == "empty" && pieces[x2 + 1][y2 - 1]->getColor() == 0) {
                    //If there is a bonus capture available set the active piece to the current piece and the
                    //turn back to blue's turn
                    bonusMove = 1;
                    activePiece = {x2, y2};
                    turn = 1;
                }
            }
            //If it's moved to a spot on the right side of the board, only check the spots to the left to avoid crash.
            if (y2 > 1 && x2 > size - 3) {
                if (pieces[x2 - 2][y2 - 2]->getType() == "empty" && pieces[x2 - 1][y2 - 1]->getColor() == 0) {
                    //If there is a bonus capture available set the active piece to the current piece and the
                    //turn back to blue's turn.
                    bonusMove = 1;
                    activePiece = {x2, y2};
                    turn = 1;
                }
            }
        }
    }
    //RED UPGRADE
    if (y2 == 0 && pieces[x2][y2]->getType() == "basic" && pieces[x2][y2]->getColor() == 1) {
        upgradePiece(x2, y2);
        //If the piece was upgrades on a capture move and there is another capture move available
        //for the new king
        if (y1 == 2 && x2 > 2 && x2 < size - 2 &&
            ((pieces[x2 - 2][y2 + 2]->getType() == "empty" && pieces[x2 - 1][y2 + 1]->getColor() == 0)
             || (pieces[x2 + 2][y2 + 2]->getType() == "empty" && pieces[x2 + 1][y2 + 1]->getColor() == 0))) {
            //Set it to the active piece and the turn to red's turn
            bonusMove = 1;
            activePiece = {x2, y2};
            turn = 1;
        }
    }
    //KING
    if (pieces[x1][y1]->getColor() == turn && pieces[x1][y1]->getType() == "king") {
        //and the clicked spot is a spot where the red piece can move
        //Can't make a basic move if it is your turn for a bonus move
        if ((x2 == x1 + 1 || x2 == x1 - 1) && (y2 == y1 - 1 || y2 == y1 + 1)  && bonusMove == 0) {
            //Move the red active piece there and set it to blue's turn
            pieces[x2][y2] = make_unique<KingPiece>(KingPiece(pieces[x1][y1]->getColor(), {x2, y2}));
            capturePiece(x1, y1);
            passTurn();
        }
        //KING CAPTURE
        //If the clicked spot is over an enemy piece
        if ((x2 == x1 + 2 || x2 == x1 - 2) && (y2 == y1 - 2 || y2 == y1 + 2)
            && pieces[(x1 + x2) / 2][(y1 + y2) / 2]->getColor() != pieces[x1][y1]->getColor()
            && pieces[(x1 + x2) / 2][(y1 + y2) / 2]->getType() != "empty") {
            //Move the red piece there and capture the blue piece
            pieces[x2][y2] = make_unique<KingPiece>(KingPiece(pieces[x1][y1]->getColor(), {x2, y2}));
            capturePiece(x1, y1);
            capturePiece((x1 + x2) / 2, (y1 + y2) / 2);
            //Set it to blue's turn and note no bonus move available.
            passTurn();
            bonusMove = 0;
            //If the piece is moved to a central spot on the board
            if (x2 > 1 && x2 < size - 2 && y2 > 1 && y2 < size - 2) {
                //CENTER BOARD BONUS CHECK
                //Check all possible spots for a bonus capture. Make sure that nearby piece is a piece of the opposite color and the far piece is empty
                if ((pieces[x2 - 2][y2 - 2]->getType() == "empty" && pieces[x2 - 1][y2 - 1]->getType() != "empty" && pieces[x2 - 1][y2 - 1]->getColor() != pieces[x2][y2]->getColor())
                    || (pieces[x2 + 2][y2 - 2]->getType() == "empty" && pieces[x2 + 1][y2 - 1]->getType() != "empty" && pieces[x2 + 1][y2 - 1]->getColor() != pieces[x2][y2]->getColor())
                    || (pieces[x2 - 2][y2 + 2]->getType() == "empty" && pieces[x2 - 1][y2 + 1]->getType() != "empty" && pieces[x2 - 1][y2 + 1]->getColor() != pieces[x2][y2]->getColor())
                    || (pieces[x2 + 2][y2 + 2]->getType() == "empty" && pieces[x2 + 1][y2 + 1]->getType() != "empty" && pieces[x2 + 1][y2 + 1]->getColor() != pieces[x2][y2]->getColor())) {
                    //If there is a bonus capture available set the active piece to the current piece and the
                    //turn back to the original turn. Can only move that piece.
                    bonusMove = 1;
                    activePiece = {x2, y2};
                    passTurn();
                }
            }
            //LEFT CENTER BONUS CHECK
            //Only check spot that are on the board. Checking spots outside the range of the board will cause a crash
            if (x2 < 2 && y2 > 1 && y2 < size - 2) {
                if ((pieces[x2 + 2][y2 - 2]->getType() == "empty" && pieces[x2 + 1][y2 - 1]->getType() != "empty" && pieces[x2 + 1][y2 - 1]->getColor() != pieces[x2][y2]->getColor())
                    || (pieces[x2 + 2][y2 + 2]->getType() == "empty" && pieces[x2 + 1][y2 + 1]->getType() != "empty" && pieces[x2 + 1][y2 + 1]->getColor() != pieces[x2][y2]->getColor())) {
                    //If there is a bonus capture available set the active piece to the current piece and the
                    //turn back to blue's turn
                    bonusMove = 1;
                    activePiece = {x2, y2};
                    passTurn();
                }
            }
            //RIGHT CENTER BONUS CHECK
            if (x2 > size - 3 && y2 > 1 && y2 < size - 2) {
                if ((pieces[x2 - 2][y2 - 2]->getType() == "empty" && pieces[x2 - 1][y2 - 1]->getType() != "empty" && pieces[x2 - 1][y2 - 1]->getColor() != pieces[x2][y2]->getColor())
                    || (pieces[x2 - 2][y2 + 2]->getType() == "empty" && pieces[x2 - 1][y2 + 1]->getType() != "empty" && pieces[x2 - 1][y2 + 1]->getColor() != pieces[x2][y2]->getColor())) {
                    //If there is a bonus capture available set the active piece to the current piece and the
                    //turn back to the original turn.
                    bonusMove = 1;
                    activePiece = {x2, y2};
                    passTurn();
                }
            }
            //TOP CENTER BONUS CHECK
            if (x2 > 1 && x2 < size - 2 && y2 < 2) {
                if ((pieces[x2 - 2][y2 + 2]->getType() == "empty" && pieces[x2 - 1][y2 + 1]->getType() != "empty" && pieces[x2 - 1][y2 + 1]->getColor() != pieces[x2][y2]->getColor())
                    || (pieces[x2 + 2][y2 + 2]->getType() == "empty" && pieces[x2 + 1][y2 + 1]->getType() != "empty" && pieces[x2 + 1][y2 + 1]->getColor() != pieces[x2][y2]->getColor())) {
                    //If there is a bonus capture available set the active piece to the current piece and the
                    //turn back to the original turn.
                    bonusMove = 1;
                    activePiece = {x2, y2};
                    passTurn();
                }
            }
            //BOTTOM CENTER BONUS CHECK
            if (x2 > 1 && x2 < size - 2 && y2 > size - 3) {
                if ((pieces[x2 - 2][y2 - 2]->getType() == "empty" && pieces[x2 - 1][y2 - 1]->getType() != "empty" && pieces[x2 - 1][y2 - 1]->getColor() != pieces[x2][y2]->getColor())
                    || (pieces[x2 + 2][y2 - 2]->getType() == "empty" && pieces[x2 + 1][y2 - 1]->getType() != "empty" && pieces[x2 + 1][y2 - 1]->getColor() != pieces[x2][y2]->getColor())) {
                    //If there is a bonus capture available set the active piece to the current piece and the
                    //turn back to the original turn.
                    bonusMove = 1;
                    activePiece = {x2, y2};
                    passTurn();
                }
            }
        }
    }
}

int Board::getSize() const {
    return size;
}

void Board::passTurn() {
    if (turn == 0){
        turn = 1;
    } else {
        turn = 0;
    }
}

int Board::getTurn() const {
    return turn;
}

void Board::setTurn(int x) {
    turn = x;
}

void Board::setActivePiece(int x, int y) {
    activePiece = {x, y};
}

point Board::getActivePiece() const {
    return activePiece;
}

int Board::getBonusMove() const {
    return bonusMove;
}

void Board::setBonusMove(int x) {
    bonusMove = x;
}

string Board::gameOver() const {
    string message = "No Win";
    int red = 0;
    int blue = 0;
    for (int c = 0; c < size; ++c) {
        for (int r = 0; r < size; ++r) {
            if (pieces[c][r]->getColor() == 0) {
                ++blue;
            }
            if (pieces[c][r]->getColor() == 1) {
                ++red;
            }
        }
    }
    if (red == 0){
        message = "Blue Wins!";
    }
    if (blue == 0){
        message = "Red Wins!";
    }
    return message;
}

/*
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Saves the game by storing the positions, types, and colors of all pieces on the board.
 */
void Menu::saveGame(const Board &b1) {
    ofstream f_out("checkersSaveData.txt", ios::app);
    if (f_out) {
        for (int c = 0; c < b1.pieces.size(); c++) {
            for (int r = 0; r < b1.pieces.size(); r++) {
                f_out << b1.pieces[c][r]->getType() << endl;
                f_out << b1.pieces[c][r]->getPosition().x << endl;
                f_out << b1.pieces[c][r]->getPosition().y << endl;
                f_out << b1.pieces[c][r]->getColor() << endl;
            }
        }
        f_out << "turn" << endl;
        f_out << b1.getTurn() << endl;
        f_out.close();
    }
}

/*
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Loads the last saved game.
 */
void Menu::loadGame(string fileName, Board &b1) {
    ifstream f_in(fileName);
    while (f_in) {
        string word = "";
        int tempX;
        int tempY;
        int tempColor;
        getline(f_in, word);
        if (word == "empty") {
            f_in >> tempX;
            f_in >> tempY;
            f_in >> tempColor;
            b1.pieces[tempX][tempY] = make_unique<EmptyPiece>(EmptyPiece({tempX, tempY}));
        }
        if (word == "basic") {
            f_in >> tempX;
            f_in >> tempY;
            f_in >> tempColor;
            b1.pieces[tempX][tempY] = make_unique<BasicPiece>(BasicPiece(tempColor, {tempX, tempY}));
        }
        if (word == "king") {
            f_in >> tempX;
            f_in >> tempY;
            f_in >> tempColor;
            b1.pieces[tempX][tempY] = make_unique<KingPiece>(KingPiece(tempColor, {tempX, tempY}));
        }
        if (word == "turn") {
            f_in >> tempX;
            b1.setTurn(tempX);
        }

    }
}

/*
 * Requires: Board b1
 * Modifies: board b1
 * Effects: Restarts the game by resetting all the pieces to their default positions
 */
void Menu::restartGame(Board &b1) {
    for (int c = 0; c < b1.getSize(); ++c) {
        for (int r = 0; r < b1.getSize(); ++r) {
            //Adds basic or empty pieces to the board depending on the position.
            if ((c % 2 != r % 2) && r < 3) {
                b1.pieces[c][r] = make_unique<BasicPiece>(BasicPiece(0, {c, r}));
            } else if ((c % 2 != r % 2) && r > b1.getSize() - 4) {
                b1.pieces[c][r] = make_unique<BasicPiece>(BasicPiece(1, {c, r}));
            } else {
                b1.pieces[c][r] = make_unique<EmptyPiece>(EmptyPiece({c, r}));;
            }
        }
    }
    //Set the turn back to red's turn
    b1.setTurn(1);
}