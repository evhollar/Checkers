#include "checkers.h"


int main() {
    cout << "Hello, World!" << endl;

    BasicPiece rbp = BasicPiece(0, {0, 0});
    BasicPiece bbp = BasicPiece(1, {50, 0});
    KingPiece rkp = KingPiece(0, {0, 50});
    KingPiece bkp = KingPiece(1, {50, 50});

    cout << rbp.getColor() << rbp.getPosition().x << rbp.getPosition().y << endl;
    cout << bbp.getColor() << bbp.getPosition().x << bbp.getPosition().y << endl;
    cout << rkp.getColor() << rkp.getPosition().x << rkp.getPosition().y << endl;
    cout << bkp.getColor() << bkp.getPosition().x << bkp.getPosition().y << endl;

    vector<BasicPiece> redBasicPieces;
    vector<KingPiece> redKingPieces;
    vector<BasicPiece> blackBasicPieces;
    vector<KingPiece> blackKingPieces;

    redBasicPieces.push_back(rbp);
    redKingPieces.push_back(rkp);
    blackBasicPieces.push_back(bbp);
    blackKingPieces.push_back(bkp);

    Menu menu1 = Menu();

    menu1.saveGame(redBasicPieces, blackBasicPieces, redKingPieces, blackKingPieces);

    return 0;
}
