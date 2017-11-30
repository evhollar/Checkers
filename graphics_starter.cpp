#include "graphics.h"
#include "shapes.h"
#include "checkers.h"

#include <random>

GLdouble width, height;
int wd;
Board b1;
vector<vector<Circle>> grid;
vector<vector<Rect>> backGrid;
Circle c1;
Menu m1;
int mouseY;
int mouseX;



void init() {
    //Create the 2D vector that will form the board pieces and the background grid
    for (int c = 0; c < b1.getSize(); ++c) {
        grid.push_back(vector<Circle>(b1.getSize()));
        backGrid.push_back(vector<Rect>(b1.getSize()));
    }
    width = 700;
    height = 700;

    //Declare all the shapes for the board
    for (int c = 0; c < b1.getSize(); ++c) {
        for (int r = 0; r < b1.getSize(); ++r) {
            grid[c][r] = Circle(1, {0, 0, 0});
            grid[c][r].set_position((width/b1.getSize())*c + (width/b1.getSize())/2, (height/b1.getSize())*r + (height/b1.getSize())/2);
            backGrid[c][r] = Rect((width/b1.getSize()), height/b1.getSize(), {1, 1, 1});
            backGrid[c][r].set_position((width/b1.getSize())*c, (height/b1.getSize())*r);

        }
    }

}
/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);
    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    //Correctly color the board and add the pieces
        for (int c = 0; c < b1.getSize(); ++c) {
            for (int r = 0; r < b1.getSize(); ++r) {
                grid[c][r].set_radius(width/b1.getSize()/2 - 2);
                if (b1.pieces[c][r]->getType() == "basic" && b1.pieces[c][r]->getColor() == 1) {
                    grid[c][r].set_fill(1, .3, .3);
                }
                if (b1.pieces[c][r]->getType() == "king" && b1.pieces[c][r]->getColor() == 1) {
                    grid[c][r].set_fill(.8, 0, 0);
                }
                if (b1.pieces[c][r]->getType() == "basic" && b1.pieces[c][r]->getColor() == 0) {
                    grid[c][r].set_fill(.3, .3, 1);
                }
                if (b1.pieces[c][r]->getType() == "king" && b1.pieces[c][r]->getColor() == 0) {
                    grid[c][r].set_fill(0, 0, .8);
                } else if (b1.pieces[c][r]->getType() == "empty") {
                    if (c % 2 == r % 2) {
                        grid[c][r].set_fill(0, 0, 0);
                        backGrid[c][r].set_fill(0, 0, 0);
                    } else {
                        grid[c][r].set_fill(1, 1, 1);
                    }
                }
            }
        }
    //Set the active piece radius to 0 to simulate it being picked up by the mouse. Its is being
    //represented by c1.
    grid[b1.getActivePiece().x][b1.getActivePiece().y].set_radius(0);

    //If the game isn't over, draw the pieces
    if (b1.gameOver() == "No Win") {
        for (int c = 0; c < b1.getSize(); ++c) {
            for (int r = 0; r < b1.getSize(); ++r) {
                backGrid[c][r].draw();
                grid[c][r].draw();
            }
        }
    }

    //Print a "K" on each king piece to help differentiate them from basic pieces.
    if (b1.gameOver() == "No Win") {
        for (int c = 0; c < b1.getSize(); ++c) {
            for (int r = 0; r < b1.getSize(); ++r) {
                if (b1.pieces[c][r]->getType() == "king" &&
                        //Wont draw a k on the board if the king is the active piece
                        ((c != b1.getActivePiece().x) || (r != b1.getActivePiece().y))){
                    string message = "K";
                    glRasterPos2i((width / b1.getSize()) * c + (width / b1.getSize()) / 2 - 9,
                                  (height / b1.getSize()) * r + (height / b1.getSize()) / 2 + 7);
                    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[0]);
                }
            }
        }
    }

    //Print the game over screen if either color has won
    if (b1.gameOver() == "Blue Wins!" || b1.gameOver() == "Red Wins!") {
        if (b1.gameOver() == "Blue Wins!") {
            glColor3f(0, 0, 1);
        }
        if (b1.gameOver() == "Red Wins!") {
            glColor3f(1, 0, 0);
        }
        glRasterPos2i(width / 2 - 60, height / 2 - 12);
        string message = b1.gameOver();
        for (int i = 0; i < message.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
        }
    }

    //Allows for players to "pick up" board pieces and move them. Colors circle c1
    //which follows the mouse depending on what color and type the active piece is.
    if(b1.pieces[b1.getActivePiece().x][b1.getActivePiece().y]->getColor() == 0){
        if(b1.pieces[b1.getActivePiece().x][b1.getActivePiece().y]->getType() == "basic") {
            c1.set_fill(.3, .3, 1);
            c1.set_radius(width/b1.getSize()/2 - 2);
        }
        if(b1.pieces[b1.getActivePiece().x][b1.getActivePiece().y]->getType() == "king") {
            c1.set_fill(0, 0, .8);
            c1.set_radius(width/b1.getSize()/2 - 2);
        }
    }
    if(b1.pieces[b1.getActivePiece().x][b1.getActivePiece().y]->getColor() == 1){
        if(b1.pieces[b1.getActivePiece().x][b1.getActivePiece().y]->getType() == "basic") {
            c1.set_fill(1, .3, .3);
            c1.set_radius(width/b1.getSize()/2 - 2);
        }
        if(b1.pieces[b1.getActivePiece().x][b1.getActivePiece().y]->getType() == "king") {
            c1.set_fill(.8, 0, 0);
            c1.set_radius(width/b1.getSize()/2 - 2);
        }
    }
    if(b1.pieces[b1.getActivePiece().x][b1.getActivePiece().y]->getType() == "empty"){
        c1.set_radius(0);
    }
    c1.draw();
    //Draws a "K" on the moving piece if it's a king piece
    if(b1.pieces[b1.getActivePiece().x][b1.getActivePiece().y]->getType() == "king"){
        glColor3f(0, 0, 0);
        string message = "K";
        glRasterPos2i(mouseX - 9, mouseY + 7);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[0]);
    }
    glFlush();  // Render now
    }

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y)
{
    // escape
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    }
    //r will restart the game
    if (key == 114) {
        m1.restartGame(b1);
    }
    //s will save the game
    if (key == 115) {
        m1.saveGame(b1);
    }
    //l will load the game
    if (key == 108) {
        m1.loadGame("checkersSaveData.txt", b1);
    }


    glutPostRedisplay();

    return;
}


void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:
            break;
        case GLUT_KEY_LEFT:
            break;
        case GLUT_KEY_RIGHT:
            break;
        case GLUT_KEY_UP:
            break;
    }

    glutPostRedisplay();

}

void cursor(int x, int y) {
    c1.set_position(x, y);
    mouseX = x;
    mouseY = y;
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {

    //Allows for the moving of pieces using mouse clicks
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        for (int c = 0; c < b1.getSize(); ++c) {
            for (int r = 0; r < b1.getSize(); ++r) {
                //If it's not an emptyPiece
                if (grid[c][r].is_overlapping(x, y)
                    //And the current piece doesn't have another available capture.
                    && b1.pieces[c][r]->getType() != "empty"
                    && b1.getBonusMove() == 0
                    //And it is that piece's turn
                    && b1.pieces[c][r]->getColor() == b1.getTurn()) {
                    //Move the piece
                    b1.setActivePiece(c, r);
                }
                //If it is a viable empty piece
                if (backGrid[c][r].is_overlapping(x, y)
                    && b1.pieces[c][r]->getType() == "empty"
                    && c % 2 != r % 2) {

                    //Move the piece to the new spot
                    //movePiece method contains game logic
                    b1.movePiece(b1.getActivePiece().x, b1.getActivePiece().y, c, r);
                }
            }
        }
    }
    //Left button sets the piece down. Changes the active piece to an empty piece
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        b1.setActivePiece(0, 0);
        if (b1.getBonusMove() == 1) {
            b1.passTurn();
            b1.setBonusMove(0);
        }
    }
    glutPostRedisplay();
}

void timer(int extra) {

    glutPostRedisplay();
    glutTimerFunc(30, timer, 0);
}

/* Main function: GLUT runs as a console application starting at main()  */
int graphicsPlay(int argc, char** argv) {

    init();

    glutInit(&argc, argv);          // Initialize GLUT

    glutInitDisplayMode(GLUT_RGBA);

    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(300, 100); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("Checkers!" /* title */ );

    // Register callback handler for window re-paint event
    glutDisplayFunc(display);

    // Our own OpenGL initialization
    initGL();

    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);

    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);

    // handles mouse movement
    glutPassiveMotionFunc(cursor);

    // handles mouse click
    glutMouseFunc(mouse);

    // handles timer
    glutTimerFunc(0, timer, 0);

    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}