#include "checkers.h"


int main() {
    cout << "Hello, World!" << endl;

    Board board1;

    //Add all the starting checkers pieces to the board;
    board1.pieces[1][0] = make_unique<BasicPiece>(BasicPiece(0, {1, 0}));
    board1.pieces[3][0] = make_unique<BasicPiece>(BasicPiece(0, {3, 0}));
    board1.pieces[5][0] = make_unique<BasicPiece>(BasicPiece(0, {5, 0}));
    board1.pieces[7][0] = make_unique<BasicPiece>(BasicPiece(0, {7, 0}));
    board1.pieces[0][1] = make_unique<BasicPiece>(BasicPiece(0, {0, 1}));
    board1.pieces[2][1] = make_unique<BasicPiece>(BasicPiece(0, {2, 1}));
    board1.pieces[4][1] = make_unique<BasicPiece>(BasicPiece(0, {4, 1}));
    board1.pieces[6][1] = make_unique<BasicPiece>(BasicPiece(0, {6, 1}));
    board1.pieces[1][2] = make_unique<BasicPiece>(BasicPiece(0, {1, 2}));
    board1.pieces[3][2] = make_unique<BasicPiece>(BasicPiece(0, {3, 2}));
    board1.pieces[5][2] = make_unique<BasicPiece>(BasicPiece(0, {5, 2}));
    board1.pieces[7][2] = make_unique<BasicPiece>(BasicPiece(0, {7, 2}));
    board1.pieces[0][5] = make_unique<BasicPiece>(BasicPiece(1, {0, 5}));
    board1.pieces[2][5] = make_unique<BasicPiece>(BasicPiece(1, {2, 5}));
    board1.pieces[4][5] = make_unique<BasicPiece>(BasicPiece(1, {4, 5}));
    board1.pieces[6][5] = make_unique<BasicPiece>(BasicPiece(1, {6, 5}));
    board1.pieces[1][6] = make_unique<BasicPiece>(BasicPiece(1, {1, 6}));
    board1.pieces[3][6] = make_unique<BasicPiece>(BasicPiece(1, {3, 6}));
    board1.pieces[5][6] = make_unique<BasicPiece>(BasicPiece(1, {5, 6}));
    board1.pieces[7][6] = make_unique<BasicPiece>(BasicPiece(1, {7, 6}));
    board1.pieces[0][7] = make_unique<BasicPiece>(BasicPiece(1, {0, 7}));
    board1.pieces[2][7] = make_unique<BasicPiece>(BasicPiece(1, {2, 7}));
    board1.pieces[4][7] = make_unique<BasicPiece>(BasicPiece(1, {4, 7}));
    board1.pieces[6][7] = make_unique<BasicPiece>(BasicPiece(1, {6, 7}));


    board1.pieces[2][5]->draw();
    board1.pieces[4][6]->draw();

    board1.movePiece(2,5,4,6);

    board1.pieces[2][5]->draw();
    board1.pieces[4][6]->draw();

    board1.upgradePiece(4, 6);
    board1.pieces[4][6]->draw();

    Menu menu1 = Menu();

    Board board2;

    menu1.saveGame(board1.pieces);
    menu1.loadGame("checkersSaveData.txt", board2.pieces);

    board2.pieces[0][0]->draw();
    board2.pieces[1][0]->draw();

    board2.capturePiece(1,0);
    board2.pieces[1][0]->draw();

    return 0;
}
