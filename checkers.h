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

struct point {
    int x;
    int y;
};

class Piece{
protected:
    int color;
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
     * Effects: Returns an int specifying color of the piece
     */
    int getColor();


    /*
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns the type of the piece
     */
    virtual string getType() const = 0;

    /*
     * Requires: nothing
     * Modifies: nothing
     * Effects: draws the Piece object
     */
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
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns the type of the piece
     */
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
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns the type of the piece
     */
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
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns the type of the piece
     */
    string getType() const override;

};

class Board{
private:
    int turn = 1;
    int size = 8;
    int bonusMove;
    point activePiece;
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

    /*
    * Requires: int x and int y
    * Modifies: pieces vector
    * Effects: Removes piece at x, y and replaces it with an empty piece
    */
    void capturePiece(int x, int y);

    /*
    * Requires: Nothing
    * Modifies: Nothing
    * Effects: Makes the BasicPiece a KingPiece
    */
    void upgradePiece(int x, int y);

    /*
    * Requires: int x1, int x2, int y1, int y2
     * Modifies: pieces vector
     * Effects: Moves the piece at location x1, y1 to location x2, y2
     */
    void movePiece(int x1, int y1, int x2, int y2);

    /*
    * Requires: Nothing
    * Modifies: Nothing
    * Effects: Returns the size of the board
    */
    int getSize();

    /*
    * Requires: Nothing
    * Modifies: Nothing
    * Effects: Sends the turn to the opposite color
    */
    void passTurn();

    /*
    * Requires: X position, Y position
    * Modifies: activePiece
    * Effects: Changes the board's active piece
    */
    void setActivePiece(int x, int y);

    /*
    * Requires: Nothing
    * Modifies: Nothing
    * Effects: Returns the current active piece
    */
    point getActivePiece();

    /*
    * Requires: Nothing
    * Modifies: Nothing
    * Effects: Returns the indicator of whether or not
     * there is a bonus move available.
    */
    int getBonusMove();

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
    void loadGame(string fileName, vector<vector<unique_ptr<Piece>>> &pieces);

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