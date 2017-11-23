#include "checkers.h"


int main() {
    cout << "Hello, World!" << endl;

    Board board1;

    //Add all the starting checkers pieces to the board;


    // uses the getType and getPosition methods, utilizes polymorphism with getType by printing out the type of piece being drawn.
    // if it is a king it will star with "king piece is located". If it is a basic piece it will print "basic piece is located".
    //the basic piece is located on (2,5) on the board, and an empty piece space is located on (4,6) on the board.

    board1.pieces[3][2]->draw();
    board1.pieces[2][3]->draw();
    //utilizes the getColor, basic piece, and king piece constructor to put an identical basic or king piece, depending on the
    //type of piece, on to the location where the piece needs to be moved. An empty piece constructor is also used in this
    //method to stand as an empty space on the board and remove the piece on the original location.  In this program, we
    //use empty piece constructors to represent empty spaces on the board in reality.
    board1.movePiece(3,2,2,3);

    //used to show the change in the piece positioning. Now an empty piece space will be in the area where the basic piece used to be,
    // at (2,5), and the basic piece  will now be at (4,6) after the above movepiece method.
    board1.pieces[3][2]->draw();
    board1.pieces[2][3]->draw();
    //utilizes the kingpiece constructor to turn the basic piece at (4,6) to a kingpiece, in the same location
    board1.upgradePiece(4, 6);
    board1.pieces[4][6]->draw();

    //makes a new menu class for saving and loading a game
    Menu menu1 = Menu();

    //makes a new board for a new game, utilizes the empty piece constructor to make a bunch of spaces ready to have pieces
    // placed on them
    Board board2;

    // utilizes the getType, getColor, and getPosition methods to save the game data on to a txt file
    menu1.saveGame(board1.pieces);

    //utilizes the empty piece, basic piece, and king piece contructor to load in the save data from the txt file
    menu1.loadGame("checkersSaveData.txt", board2.pieces);

    //shows that the loadgame method works.  In the beginning of main, a basic piece was placed at (1,0).  There was never
    // any piece in (0,0).  After saving and reloading, the basic piece at (1,0) is still there, and there is still an
    // empty space at (0,0).
    board2.pieces[0][0]->draw();
    board2.pieces[1][0]->draw();

    //utilizes the empty piece constructor to remove the piece in the location (1,0).  From the draw method above, we see
    //that there was once a basic piece in that location.  Since it was captured though with this method, it is no longer there,
    // and there exists now only a empty space.
    board2.capturePiece(1,0);
    board2.pieces[1][0]->draw();
    board2.pieces[3][6]->draw();

    return 0;
}
