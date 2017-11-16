#include "checkers.h"


int main() {
    cout << "Hello, World!" << endl;

    Board board1;

    BasicPiece rbp1 = BasicPiece(0, {1, 0});
    BasicPiece rbp2 = BasicPiece(0, {3, 0});
    BasicPiece rbp3 = BasicPiece(0, {5, 0});
    BasicPiece rbp4 = BasicPiece(0, {7, 0});
    BasicPiece rbp5 = BasicPiece(0, {0, 1});
    BasicPiece rbp6 = BasicPiece(0, {2, 1});
    BasicPiece rbp7 = BasicPiece(0, {4, 1});
    BasicPiece rbp8 = BasicPiece(0, {6, 1});
    BasicPiece rbp9 = BasicPiece(0, {1, 2});
    BasicPiece rbp10 = BasicPiece(0, {3, 2});
    BasicPiece rbp11 = BasicPiece(0, {5, 2});
    BasicPiece rbp12 = BasicPiece(0, {7, 2});
    BasicPiece bbp1 = BasicPiece(1, {0, 5});
    BasicPiece bbp2 = BasicPiece(1, {2, 5});
    BasicPiece bbp3 = BasicPiece(1, {4, 5});
    BasicPiece bbp4 = BasicPiece(1, {6, 5});
    BasicPiece bbp5 = BasicPiece(1, {1, 6});
    BasicPiece bbp6 = BasicPiece(1, {3, 6});
    BasicPiece bbp7 = BasicPiece(1, {5, 6});
    BasicPiece bbp8 = BasicPiece(1, {7, 6});
    BasicPiece bbp9 = BasicPiece(1, {0, 7});
    BasicPiece bbp10 = BasicPiece(1, {2, 7});
    BasicPiece bbp11 = BasicPiece(1, {4, 7});
    BasicPiece bbp12 = BasicPiece(1, {6, 7});

    board1.pieces.push_back(make_unique<BasicPiece>(rbp1));
    board1.pieces.push_back(make_unique<BasicPiece>(rbp2));
    board1.pieces.push_back(make_unique<BasicPiece>(rbp3));
    board1.pieces.push_back(make_unique<BasicPiece>(rbp4));
    board1.pieces.push_back(make_unique<BasicPiece>(rbp5));
    board1.pieces.push_back(make_unique<BasicPiece>(rbp6));
    board1.pieces.push_back(make_unique<BasicPiece>(rbp7));
    board1.pieces.push_back(make_unique<BasicPiece>(rbp8));
    board1.pieces.push_back(make_unique<BasicPiece>(rbp9));
    board1.pieces.push_back(make_unique<BasicPiece>(rbp10));
    board1.pieces.push_back(make_unique<BasicPiece>(rbp11));
    board1.pieces.push_back(make_unique<BasicPiece>(rbp12));
    board1.pieces.push_back(make_unique<BasicPiece>(bbp1));
    board1.pieces.push_back(make_unique<BasicPiece>(bbp2));
    board1.pieces.push_back(make_unique<BasicPiece>(bbp3));
    board1.pieces.push_back(make_unique<BasicPiece>(bbp4));
    board1.pieces.push_back(make_unique<BasicPiece>(bbp5));
    board1.pieces.push_back(make_unique<BasicPiece>(bbp6));
    board1.pieces.push_back(make_unique<BasicPiece>(bbp7));
    board1.pieces.push_back(make_unique<BasicPiece>(bbp8));
    board1.pieces.push_back(make_unique<BasicPiece>(bbp9));
    board1.pieces.push_back(make_unique<BasicPiece>(bbp10));
    board1.pieces.push_back(make_unique<BasicPiece>(bbp11));
    board1.pieces.push_back(make_unique<BasicPiece>(bbp12));

    board1.pieces[6]->draw();
    board1.pieces[15]->draw();

    Menu menu1 = Menu();

    Board board2;

      menu1.saveGame(board1.pieces);
//    menu1.loadGame("checkersSaveData.txt", board2.pieces);
//    cout << redBasicPieces.size() << endl;
//    cout << redBasicPieces[0].getType() << " "<< redBasicPieces[0].getColor() << redBasicPieces[0].getPosition().x << redBasicPieces[0].getPosition().y << endl;
//    cout << redKingPieces[0].getType() << " "<< redKingPieces[0].getColor() << redKingPieces[0].getPosition().x << redKingPieces[0].getPosition().y << endl;




    return 0;
}
