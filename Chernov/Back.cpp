
#include "Header.h"
int movePlayer(int currentPlayer, int roll)
{
    int newPosition = currentPlayer + roll;
    // Define the positions of snakes and ladders on the 
    // board 
    int snakesAndLadders[101];

    for (int i = 0; i <= 100; i++) {
        snakesAndLadders[i] = 0;
    }

    // here positive weights represent a ladder 
    // and negative weights represent a snake. 
    snakesAndLadders[6] = 40;
    snakesAndLadders[23] = -10;
    snakesAndLadders[45] = -7;
    snakesAndLadders[61] = -18;
    snakesAndLadders[65] = -8;
    snakesAndLadders[77] = 5;
    snakesAndLadders[98] = -68;
    int newSquare;
    if (newPosition > 100) {
        newSquare
            = currentPlayer + 0;
    }
    else {
        newSquare
            = newPosition + snakesAndLadders[newPosition];
    }

    return newSquare;
}
int ÑhooseVar() {
    return _getch();
}
int rollDie() { return rand() % 6 + 1; }
