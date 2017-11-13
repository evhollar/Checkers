//
// Created by Bastien Taylor on 11/13/17.
//

#ifndef JEB2020_CHECKERS_H
#define JEB2020_CHECKERS_H

#include <iostream>
#include <vector>
using namespace std;

struct point{
    int x;
    int y;
};

class Board{
private:
    int turn;
    int size;
    vector<Piece> redPieces;
    vector<Piece> blackPieces;

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
    Piece getPieces();

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
    void saveGame();

    /*
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: Loads the game
     */
    void loadGame();

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

class Piece{
private:
    int color;
    int taken;
    point position;

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
    virtual point getPosition();

    /*
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: Captures the piece
     */
    virtual void capture();

    /*
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: Returns an int specifying color of the piece
     */
    virtual int getColor();

    /*
     * Requires: point Position
     * Modifies: Position of the piece
     * Effects: Moves the piece
     */
    virtual void movePiece(point p);
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

    //Getters
    /*
    * Requires: Nothing
    * Modifies: Nothing
    * Effects: Returns int specifying color
    */
    int getColor() override;

    /*
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: Returns the position of the piece
     */
    point getPosition() override;

    /*
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: Captures the piece
     */
    void capture() override;

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

    //Getters
    /*
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: Returns int specifying color
     */
    int getColor() override;

    /*
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: Returns the position of the piece
     */
    point getPosition() override;

    /*
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: Captures the piece
     */
    void capture() override;

    /*
     * Requires: point position
     * Modifies: Position
     * Effects: Moves the piece to position p
     */
    void movePiece(point p) override;

};

#endif //JEB2020_CHECKERS_H