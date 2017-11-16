//
// Created by Bastien Taylor on 11/13/17.
//

#ifndef JEB2020_CHECKERS_H
#define JEB2020_CHECKERS_H

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

struct point{
    int x;
    int y;
};

class Piece{
protected:
    int color;
    bool taken;
    point position;
    string type;

public:

    //Constructor
    /*
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: Creates a piece
     */
    Piece();

    //Getters
    /*
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: Gets the position of the piece
     */
    point getPosition();

    /*
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: Captures the piece
     */
    void capture();

    /*
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: Returns an int specifying color of the piece
     */
    int getColor();


    string getType();

    /*
     * Requires: point Position
     * Modifies: Position of the piece
     * Effects: Moves the piece
     */
    virtual void movePiece(point p) = 0;
};

class BasicPiece : public Piece{
public:
    //Constructor
    /*
     * Requires: Int for color and point for position
     * Modifies: color and position
     * Effects: Creates a piece with color c at point p
     */
    BasicPiece(int c, point p);

    /*
     * Requires: point position
     * Modifies: Position
     * Effects: Moves the piece to position p
     */
    void movePiece(point p) override;

    /*
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: Makes the BasicPiece a KingPiece
     */
    void upgradePiece();

};

class KingPiece : public Piece{
public:
    //Constructor
    /*
    * Requires: Int for color and point for position
    * Modifies: color and position
    * Effects: Creates a piece with color c at point p
    */
    KingPiece(int c, point p);

    /*
     * Requires: point position
     * Modifies: Position
     * Effects: Moves the piece to position p
     */
    void movePiece(point p) override;

};

class Board{
private:
    int turn;
    int size;
    vector<BasicPiece> redBasicPieces;
    vector<KingPiece> redKingPieces;
    vector<BasicPiece> blackBasicPieces;
    vector<KingPiece> blackKingPieces;

public:
    // Constructors
    /*
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: Creates a Board object
     */
    Board();

    //Getters
    /*
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: Return all pieces
     */
    vector<BasicPiece> getRedBasicPieces();

    /*
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: Return all pieces
     */
    vector<KingPiece> getRedKingPieces();

    /*
    * Requires: Nothing
    * Modifies: Nothing
    * Effects: Return all pieces
    */
    vector<BasicPiece> getBlackBasicPieces();

    /*
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: Return all pieces
     */
    vector<KingPiece> getBlackKingPieces();


    /*
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: Draws the board with all pieces
     */
    void draw();
};

class Menu{
public:
    /*
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: Saves the game
     */
    void saveGame(vector<BasicPiece> &rbp, vector<BasicPiece> &bbp, vector<KingPiece> &rkp, vector<KingPiece> &bkp);

    /*
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: Loads the game
     */
    void loadGame(string fileName, vector<BasicPiece> &rbp, vector<BasicPiece> &bbp, vector<KingPiece> &rkp, vector<KingPiece> &bkp);

    /*
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: Exits the game
     */
    void exitGame();

    /*
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: Restarts the game
     */
    void restartGame();

};

#endif //JEB2020_CHECKERS_H