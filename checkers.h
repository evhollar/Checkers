//
// Created by Bastien Taylor on 11/13/17.
//

#ifndef JEB2020_CHECKERS_H
#define JEB2020_CHECKERS_H

#include <fstream>
#include <iomanip>
#include <iostream>
#include <memory>
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


    virtual string getType() const = 0;

    /*
     * Requires: point Position
     * Modifies: Position of the piece
     * Effects: Moves the piece
     */
    virtual void movePiece(point p) = 0;

    void draw();
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

    string getType() const override;

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

    string getType() const override;

};

class EmptyPiece : public Piece{
public:
    //Constructor
    /*
     * Requires: Int for color and point for position
     * Modifies: color and position
     * Effects: Creates a piece with color c at point p
     */
    EmptyPiece(point p);

    /*
     * Requires: point position
     * Modifies: Position
     * Effects: Moves the piece to position p
     */
    void movePiece(point p) override;

    string getType() const override;

};

class Board{
private:
    int turn;
    int size;
public:
    vector<vector<unique_ptr<Piece>>> pieces;

    // Constructors
    /*
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: Creates a Board object
     */
    Board();

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
    void saveGame(const vector<vector<unique_ptr<Piece>>> &pieces);

    /*
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: Loads the game
     */
    void loadGame(string fileName, vector<unique_ptr<Piece>> pieces);

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