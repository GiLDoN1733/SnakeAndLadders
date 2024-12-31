// C Program to implement Snake and Ladder Game 
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include<iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
#define UpStr   "\t\t\t\t\t\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcb" \
                "\xcd\xcd\xcd\xcd\xcd\xcd\xcb" \
                "\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd\xcd\xcd\xcd\xcd\xcd\xcb" \
                "\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd\xcd\xcd\xcd\xcd\xcd\xcb" \
                "\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd\xcd\xcd\xcd\xcd\xcd\xcb" \
                "\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n"
#define DownStr "\t\t\t\t\t\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xcd\xca" \
                "\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xcd\xca" \
                "\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xcd\xca" \
                "\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xcd\xca" \
                "\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n"
#define DownStrZ "\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xcd\xca" \
                "\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xcd\xca" \
                "\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xcd\xca" \
                "\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xcd\xca" \
                "\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n"

#define MidStr  "\n\t\t\t\t\t\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xce" \
                "\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xce" \
                "\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xce" \
                "\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xce" \
                "\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xce" \
                "\xcd\xcd\xcd\xcd\xcd\xcd\xb9\n"

// Function to roll a six-sided die 
int rollDie() { return rand() % 6 + 1; }

// global variables to store postions of player1 and player2 
int player1 = 0, player2 = 0;

// Function to print the board 
void printBoard()
{
    SetConsoleCP(866);
    SetConsoleOutputCP(866);
    // logic to print a snake-ladder Game board 
    // programmer can implement their own logic for the board, 
    // this is one way to print a snake ladder board. 
    int board[101];
    for (int i = 1; i <= 100; i++) {
        board[i] = i;
    }

    int alt = 0; // to switch between the alternate nature of the board 
    int iterLR = 101; // iterator to print from left to right 
    int iterRL = 80; // iterator to print from right to left 
    int val = 100;

    printf("\n");
    printf(UpStr);
    while (val--) {
        if (alt == 0) {
            --iterLR;
            while (iterLR % 10 != 1) {
                
                if (iterLR == 77)
                    printf("\xba\x1b[32m77>>82\x1b[0m");
                else if (iterLR == 98)
                    printf("\xba\x1b[31m98>>30\x1b[0m");
                else if(iterLR%10==0)
                    printf("\t\t\t\t\t\xba      ");
                else
                    printf("\xba      ");
            iterLR--;
            }
            if (iterLR % 10 == 1) {
                printf("\xba      \xba");
            }
            if (iterLR % 10 == 1) {
                iterLR += 9;
                printf("\n");
            }
            while (iterLR % 10 != 1) {
                if (iterLR % 10 == 0)
                    printf("\t\t\t\t\t\xba  %3d ", board[iterLR]);
                else
                    printf("\xba  %3d ", board[iterLR]);
                iterLR--;
            }
            if (iterLR % 10 == 1) {
                printf("\xba  %3d \xba", board[iterLR]);
            }
                if (iterLR % 10 == 1) {
                    iterLR += 9;
                    printf("\n");
                }
                while (iterLR % 10 != 1) {
                    
                    if (iterLR == player1 && iterLR % 10 == 0 && iterLR == player2) {
                        printf("\t\t\t\t\t\xba\x1b[33m#P1=P2\x1b[0m");
                    }
                    else if (iterLR == player1 && iterLR == player2) {
                        printf("\xba\x1b[33m#P1=P2\x1b[0m");
                    }
                    else if (iterLR == player1 && player1 % 10 == 0) {
                        printf("\t\t\t\t\t\xba\x1b[34m  #P1 \x1b[0m");
                    }
                    else if (iterLR == player2 && player2 % 10 == 0) {
                        printf("\t\t\t\t\t\xba\x1b[36m  #P2 \x1b[0m");
                    }
                    else if (iterLR == player1) {
                        printf("\xba\x1b[34m  #P1 \x1b[0m");
                    }
                    else if (iterLR == player2) {
                        printf("\xba\x1b[36m  #P2 \x1b[0m");
                    }
                    else if (iterLR != player2 && iterLR != player1 && iterLR % 10 == 0) {
                        printf("\t\t\t\t\t\xba\x1b[35m      \x1b[0m");
                    }
                    else if (iterLR != player2 && iterLR != player1 ) {
                        printf("\xba\x1b[35m      \x1b[0m");
                    }
                    iterLR--;
                }	
                if (iterLR != player2 && iterLR != player1) {
                    printf("\xba\x1b[35m      \x1b[0m\xba");
                }
                else if (iterLR == player1 && iterLR % 10 == 1 && iterLR == player2) {
                    printf("\xba\x1b[33m#P1=P2\x1b[0m\xba");
                }
                else if (iterLR == player1 && player1 % 10 == 1) {
                    printf("\xba\x1b[34m  #P1 \x1b[0m\xba");
                }
                else if (iterLR == player2 && player2 % 10 == 1) {
                    printf("\xba\x1b[36m  #P2 \x1b[0m\xba");
                }

                if (iterLR % 10 == 1) {
                    printf(MidStr);
                    alt = 1;
                    iterLR -= 10;
                }
        }
        else {
                    ++iterRL;
                    while (iterRL % 10 != 0) {
                        if (iterRL == 61)
                            printf("\t\t\t\t\t\xba\x1b[31m61>>43\x1b[0m");
                        else if (iterRL == 6)
                            printf("\xba\x1b[32m6>>>46\x1b[0m");
                        else if (iterRL == 77)
                            printf("\xba\x1b[32m77>>82\x1b[0m");
                        else if (iterRL == 23)
                            printf("\xba\x1b[31m23>>13\x1b[0m");
                        else if (iterRL == 45)
                            printf("\xba\x1b[31m45>>38\x1b[0m");
                        else if (iterRL == 65)
                            printf("\xba\x1b[31m65>>57\x1b[0m");
                        else if (iterRL == 98)
                            printf("\xba\x1b[31m98>>43\x1b[0m");
                        else if (iterRL % 10 == 1)
                            printf("\t\t\t\t\t\xba      ");
                        else
                            printf("\xba      ");
                        iterRL++;
                    }
                    if (iterRL % 10 == 0) {
                        printf("\xba      \xba");
                        printf("\n");
                        iterRL -= 9;
                    }
                    while (iterRL % 10 != 0) {
                        if (iterRL % 10 == 1)
                            printf("\t\t\t\t\t\xba  %3d ", board[iterRL]);
                        else
                            printf("\xba  %3d ", board[iterRL]);
                        iterRL++;
                    }
                    if (iterRL % 10 == 0){
                        printf("\xba  %3d \xba", board[iterRL]);
                        printf("\n");
                        iterRL -= 9;
                    }
                    while (iterRL % 10 != 0) {
                        
                        if (iterRL == player1 && iterRL % 10 == 1 && iterRL == player2) {
                            printf("\t\t\t\t\t\xba\x1b[33m#P1=P2\x1b[0m");
                        }
                        else if (iterRL == player1 && iterRL == player2) {
                            printf("\xba\x1b[33m#P1=P2\x1b[0m");
                        }
                        else if (iterRL == player1 && player1 % 10 == 1) {
                            printf("\t\t\t\t\t\xba\x1b[34m  #P1 \x1b[0m");
                        }
                        else if (iterRL == player2 && player2 % 10 == 1) {
                            printf("\t\t\t\t\t\xba\x1b[36m  #P2 \x1b[0m");
                        }
                        else if (iterRL == player1) {
                            printf("\xba\x1b[34m  #P1 \x1b[0m");
                        }
                        else if (iterRL == player2) {
                            printf("\xba\x1b[36m  #P2 \x1b[0m");
                        }
                        else if (iterRL != player2 && iterRL != player1 && iterRL % 10 == 1) {
                            printf("\t\t\t\t\t\xba\x1b[35m      \x1b[0m");
                        }
                        else if (iterRL != player2 && iterRL != player1) {
                            printf("\xba\x1b[35m      \x1b[0m");
                        }
                        iterRL++;
                    }
                    if (iterRL != player2 && iterRL != player1) {
                        printf("\xba\x1b[35m      \x1b[0m\xba");
                    }
                    else if (iterRL == player1 && iterRL == player2) {
                        printf("\xba\x1b[33m#P1=P2\x1b[0m\xba");
                    }
                    else if (iterRL == player1 && player1 % 10 == 0) {
                        printf("\xba\x1b[34m  #P1 \x1b[0m\xba");
                    }
                    else if (iterRL == player2 && player2 % 10 == 0) {
                        printf("\xba\x1b[36m  #P2 \x1b[0m\xba");
                    }
                    
                    
            
                    
            if (iterRL % 10 == 0 && iterRL != 10) {
                printf(MidStr);
                alt = 0;
                iterRL -= 30;
            }
        }
        if (iterRL == 10)
            break;
    }
    printf("\n");
    if (player1 == 0 && player2 == 0) {
        //printf("",player1, player2, DownStr);
//		printf("\x1b[34m%-2i\x1b[0m  \x1b[35m%2i\x1b[0m", player1, player2,DownStr); // позиции игроков
        printf("\t\t\t\x1b[33m#P1===P2\x1b[0m\t" DownStrZ);// позиции игроков
    }
    else if (player1 == 0 && player2!=0) {
        printf("\t\t\t\x1b[34m#P1     \x1b[0m\t" DownStrZ);// позиции игрока 1
    }
    else if (player2 == 0 && player1 != 0) {
        printf("\t\t\t\x1b[36m     #P2\x1b[0m\t" DownStrZ);// позиции игрока 1
    }
    else
    printf(DownStr);
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

// Function to move the player 
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
int СhooseVar() {
    return _getch();
}
void MainMenuText()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("cls");
    printf("\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\x1b[31m   ######  ##    ##    ###    ##    ## ########  #######     \x1b[0m\n");
    printf("\t\t\t\t\t\t\x1b[31m  ##    ## ###   ##   ## ##   ##   ##  ##       ##    ##     \x1b[0m\n");
    printf("\t\t\t\t\t\t\x1b[31m  ##       ####  ##  ##   ##  ##  ##   ##       ##           \x1b[0m\n");
    printf("\t\t\t\t\t\t\x1b[31m   ######  ## ## ## ##     ## #####    ######    ######      \x1b[0m\n");
    printf("\t\t\t\t\t\t\x1b[31m        ## ##  #### ######### ##  ##   ##             ##     \x1b[0m\n");
    printf("\t\t\t\t\t\t\x1b[31m  ##    ## ##   ### ##     ## ##   ##  ##       ##    ##     \x1b[0m\n");
    printf("\t\t\t\t\t\t\x1b[31m   ######  ##    ## ##     ## ##    ## ########  ######      \x1b[0m\n\n");
    printf("\t\t\t\t\t\t\x1b[33m     ###    ##    ## ########  \x1b[0m\n");
    printf("\t\t\t\t\t\t\x1b[33m    ## ##   ###   ## ##     ## \x1b[0m            Игра\n");
    printf("\t\t\t\t\t\t\x1b[33m   ##   ##  ####  ## ##     ## \x1b[0m    1. Игрок  VS  Игрок\n");
    printf("\t\t\t\t\t\t\x1b[33m  ##     ## ## ## ## ##     ## \x1b[0m    2. Игрок  VS Компьютер\n");
    printf("\t\t\t\t\t\t\x1b[33m  ######### ##  #### ##     ## \x1b[0m    3. Выход из игры\n");
    printf("\t\t\t\t\t\t\x1b[33m  ##     ## ##   ### ##     ## \x1b[0m    4. Помощь\n");
    printf("\t\t\t\t\t\t\x1b[33m  ##     ## ##    ## ########                                \x1b[0m\n\n");
    printf("\t\t\t\t\t\t\x1b[32m  ##          ###    ########  ########  ######## ########   \x1b[0m\n");
    printf("\t\t\t\t\t\t\x1b[32m  ##         ## ##   ##     ## ##     ## ##       ##     ##  \x1b[0m\n");
    printf("\t\t\t\t\t\t\x1b[32m  ##        ##   ##  ##     ## ##     ## ##       ##     ##  \x1b[0m\n");
    printf("\t\t\t\t\t\t\x1b[32m  ##       ##     ## ##     ## ##     ## ######   ########   \x1b[0m\n");
    printf("\t\t\t\t\t\t\x1b[32m  ##       ######### ##     ## ##     ## ##       ##   ##    \x1b[0m\n");
    printf("\t\t\t\t\t\t\x1b[32m  ##       ##     ## ##     ## ##     ## ##       ##    ##   \x1b[0m\n");
    printf("\t\t\t\t\t\t\x1b[32m  ######## ##     ## ########  ########  ######## ##     ##  \x1b[0m\n\n");
}
void Player1Wins() {
    system("cls");
    printf("\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\x1b[34m  ########  ##          ###    ##    ## ######## ########        ##\x1b[0m\n");
    printf("\t\t\t\t\t\x1b[34m  ##     ## ##         ## ##    ##  ##  ##       ##     ##     ####\x1b[0m\n");
    printf("\t\t\t\t\t\x1b[34m  ##     ## ##        ##   ##    ####   ##       ##     ##       ##\x1b[0m\n");
    printf("\t\t\t\t\t\x1b[34m  ########  ##       ##     ##    ##    ######   ########        ##\x1b[0m\n");
    printf("\t\t\t\t\t\x1b[34m  ##        ##       #########    ##    ##       ##   ##         ##\x1b[0m\n");
    printf("\t\t\t\t\t\x1b[34m  ##        ##       ##     ##    ##    ##       ##    ##        ##\x1b[0m\n");
    printf("\t\t\t\t\t\x1b[34m  ##        ######## ##     ##    ##    ######## ##     ##     ######\x1b[0m\n\n");
    printf("\t\t\t\t\t\x1b[34m                 ##      ## #### ##    ## ####\x1b[0m\n");
    printf("\t\t\t\t\t\x1b[34m                 ##  ##  ##  ##  ###   ## ####\x1b[0m\n");
    printf("\t\t\t\t\t\x1b[34m                 ##  ##  ##  ##  ####  ## ####\x1b[0m\n");
    printf("\t\t\t\t\t\x1b[34m                 ##  ##  ##  ##  ## ## ##  ##\x1b[0m\n");
    printf("\t\t\t\t\t\x1b[34m                 ##  ##  ##  ##  ##  ####\x1b[0m\n");
    printf("\t\t\t\t\t\x1b[34m                 ##  ##  ##  ##  ##   ### ####\x1b[0m\n");
    printf("\t\t\t\t\t\x1b[34m                  ###  ###  #### ##    ## ####\x1b[0m\n");
    system("PAUSE");
}
void Player2Wins() {
    system("cls");
    printf("\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\x1b[36m  ########  ##          ###    ##    ## ######## ########      #######\x1b[0m\n");
    printf("\t\t\t\t\t\x1b[36m  ##     ## ##         ## ##    ##  ##  ##       ##     ##    ##     ##\x1b[0m\n");
    printf("\t\t\t\t\t\x1b[36m  ##     ## ##        ##   ##    ####   ##       ##     ##           ##\x1b[0m\n");
    printf("\t\t\t\t\t\x1b[36m  ########  ##       ##     ##    ##    ######   ########      #######\x1b[0m\n");
    printf("\t\t\t\t\t\x1b[36m  ##        ##       #########    ##    ##       ##   ##      ##\x1b[0m\n");
    printf("\t\t\t\t\t\x1b[36m  ##        ##       ##     ##    ##    ##       ##    ##     ##\x1b[0m\n");
    printf("\t\t\t\t\t\x1b[36m  ##        ######## ##     ##    ##    ######## ##     ##    #########\x1b[0m\n\n");
    printf("\t\t\t\t\t\x1b[36m                 ##      ## #### ##    ## ####\x1b[0m\n");
    printf("\t\t\t\t\t\x1b[36m                 ##  ##  ##  ##  ###   ## ####\x1b[0m\n");
    printf("\t\t\t\t\t\x1b[36m                 ##  ##  ##  ##  ####  ## ####\x1b[0m\n");
    printf("\t\t\t\t\t\x1b[36m                 ##  ##  ##  ##  ## ## ##  ##\x1b[0m\n");
    printf("\t\t\t\t\t\x1b[36m                 ##  ##  ##  ##  ##  ####\x1b[0m\n");
    printf("\t\t\t\t\t\x1b[36m                 ##  ##  ##  ##  ##   ### ####\x1b[0m\n");
    printf("\t\t\t\t\t\x1b[36m                  ###  ###  #### ##    ## ####\x1b[0m\n");
    system("PAUSE");
}
void ComtuperWins() {
    system("cls");
    printf("\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\x1b[31m   ######   #######  ##     ## ########  ##     ## ######## ######## ########\x1b[0m\n");
    printf("\t\t\t\t\t\x1b[31m  ##    ## ##     ## ###   ### ##     ## ##     ##    ##    ##       ##     ##\x1b[0m\n");
    printf("\t\t\t\t\t\x1b[31m  ##       ##     ## #### #### ##     ## ##     ##    ##    ##       ##     ##\x1b[0m\n");
    printf("\t\t\t\t\t\x1b[31m  ##       ##     ## ## ### ## ########  ##     ##    ##    ######   ########\x1b[0m\n");
    printf("\t\t\t\t\t\x1b[31m  ##       ##     ## ##     ## ##        ##     ##    ##    ##       ##   ##\x1b[0m\n");
    printf("\t\t\t\t\t\x1b[31m  ##    ## ##     ## ##     ## ##        ##     ##    ##    ##       ##    ##\x1b[0m\n");
    printf("\t\t\t\t\t\x1b[31m   ######   #######  ##     ## ##         #######     ##    ######## ##     ##\x1b[0m\n\n");
    printf("\t\t\t\t\t\x1b[31m                       ##      ## #### ##    ## ####\x1b[0m\n");
    printf("\t\t\t\t\t\x1b[31m                       ##  ##  ##  ##  ###   ## ####\x1b[0m\n");
    printf("\t\t\t\t\t\x1b[31m                       ##  ##  ##  ##  ####  ## ####\x1b[0m\n");
    printf("\t\t\t\t\t\x1b[31m                       ##  ##  ##  ##  ## ## ##  ##\x1b[0m\n");
    printf("\t\t\t\t\t\x1b[31m                       ##  ##  ##  ##  ##  ####\x1b[0m\n");
    printf("\t\t\t\t\t\x1b[31m                       ##  ##  ##  ##  ##   ### ####\x1b[0m\n");
    printf("\t\t\t\t\t\x1b[31m                        ###  ###  #### ##    ## ####\x1b[0m\n");
    system("PAUSE");
}
void MenuHelpPlayer() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("cls");
    printf("\n\n\n\n\n\n\n");
    printf("\t\t\t Правила: В начале игры ( Player vs Player; Player vs Computer) за полем находятся два игрока.\n");
    printf("\t\t\t В начале хода, каждый игрок бросает кубик, значения которого находятся от 1 до 6. Выпавшее число, будет указывать\n");
    printf("\t\t\t на то количество клеток, которое он должен пропустить. После хода перовго игрока происходит ход вторго игрока\n");
    printf("\t\t\t На поле присутствуют клетки, сверху помеченные как Змея и Летсница . При переходе на клетку со змеёй,\n");
    printf("\t\t\t игрок должен перейти на клетку указанную сверху нумерации клетки.\n");
    printf("\t\t\tПример: запись 71>>38 обозначает что игрок с 71 клетки\n");
    printf("\t\t\t игрок должен перейти на 38 клетку, аналогично запись 65>>88.\n");
    printf("\t\t\tКонец игры наступает когда один из игроков достигает конечной клетки (100).\n");
    printf("\t\t\t Если игрок находится за одну клетку до финиша и выбрасывает число при котором\n");
    printf("\t\t\tсумма текущей позиции и выброшенного числа больше номера конечной клетки,\n");
    printf("\t\t\t то игрок пропускает ход.\n\n");
    printf("\t\t\t\t\tПриятной игры\n\n");
    system("PAUSE");
}
int main()
{
    system("mode con cols=160 lines=50");
    system("title -=Snakes and Ladder=-");
    HWND hWindowConsole = GetConsoleWindow();
    MoveWindow(hWindowConsole, 0, 0, 1200, 900, TRUE);
    HMENU hm;
    hm = GetSystemMenu(hWindowConsole, FALSE);
    RemoveMenu(hm, SC_SIZE, MF_BYCOMMAND | MF_REMOVE);
    RemoveMenu(hm, SC_MAXIMIZE, MF_BYCOMMAND | MF_REMOVE);
    DrawMenuBar(hWindowConsole);
    srand(time(0));
    // Initialize random seed 
    int PlayTheGame = 0;
    while (!PlayTheGame) {
        player1 = 0, player2 = 0;
        MainMenuText();
        setlocale(LC_CTYPE, "UTF-8");
        switch (СhooseVar()) {
        case (49): {
            int currentPlayer = 1;
            int won = 0;
            system("mode con cols=160 lines=50");
            //HWND window_header = GetConsoleWindow();
            //SetWindowPos(window_header, HWND_TOP, 0, 0, 300, 300, NULL);
            printBoard();
            while (!won) {
                printf("\n\t Игрок %d,нажми ENTER что бы бросить кубик...",currentPlayer);
                // Wait for the player to press Enter 
                switch (_getch()) {
                case(13): {
                    if (currentPlayer == 1) {
                        int roll = rollDie();
                        system("cls");
                        player1 = movePlayer(player1, roll);
                        printBoard();
                        printf("\tИгроку 1 выпало число %d.\n", roll);
                        printf("\tИгрок 1 сейчас находится на %d клетке.\n\n", player1);
                        if (player1 == 100) {
                            Player1Wins();
                            Sleep(3000);
                            won = 1;
                            break;
                        }
                        currentPlayer = (currentPlayer == 1) ? 2 : 1;
                    }
                    else {
                        int roll = rollDie();
                        system("cls");
                        player2 = movePlayer(player2, roll);
                        printBoard();
                        printf("\tИгроку 2 выпало число %d.\n", roll);
                        printf("\tИгрок 2 сейчас находится на %d клетке.\n\n", player2);
                        if (player2 == 100) {
                            Player2Wins();
                            Sleep(3000);
                            won = 1;
                            break;
                        }
                        currentPlayer = (currentPlayer == 1) ? 2 : 1;
                    }
                    break;
                }
                default: {
                    system("cls");
                    printBoard();
                    printf("\tИгрок 1 сейчас находится на %d клетке.\n\n", player1);
                    printf("\tИгрок 2 сейчас находится на %d клетке.\n\n", player2);
                    printf("\tНеверный символ, нажмите ENTER для продолжения...");
                    break;
                }


                }
            }
            break;
        }
        case(50): {
            int currentPlayer = 1;
            int won = 0;
            system("mode con cols=160 lines=50");

            //HWND window_header = GetConsoleWindow();
            //SetWindowPos(window_header, HWND_TOP, 0, 0, 300, 300, NULL);
            printBoard();
            printf(
                "\tИгрок % d, нажми ENTER что бы бросить кубик...",
                currentPlayer);
            while (!won) {
                // Wait for the player to press Enter 
                switch (_getch()) {
                case(13): {
                    int roll = rollDie();
                    system("cls");
                    player1 = movePlayer(player1, roll);
                    printBoard();
                    printf("\tИгроку 1 выпало число %d.\n", roll);
                    printf("\tИгрок 1 сейчас находится на %d клетке.\n\n", player1);
                    if (player1 == 100) {
                        Player1Wins();
                        Sleep(3000);
                        won = 1;
                        break;
                    }
                    Sleep(300);
                    currentPlayer = (currentPlayer == 1) ? 2 : 1;
                    roll = rollDie();
                    system("cls");
                    player2 = movePlayer(player2, roll);
                    printBoard();
                    printf("\tКомпьютеру выпало число %d.\n", roll);
                    printf("\tКомпьютер сейчас находится на %d клетке.\n\n", player2);
                    printf("\n Игрок 1,нажми ENTER что бы бросить кубик...");
                    if (player2 == 100) {
                        ComtuperWins();
                        Sleep(3000);
                        won = 1;
                        break;
                    }
                    currentPlayer = (currentPlayer == 1) ? 2 : 1;
                    break;
                };
                default: {
                    system("cls");
                    printBoard();
                    printf("\tИгрок 1 сейчас находится на %d клетке.\n\n", player1);
                    printf("\tКомпьютер сейчас находится на %d клетке.\n\n", player2);
                    printf("\tНеверный символ, нажмите ENTER для продолжения...");
                    break;
                }
                }
            }
            break;
        }
        case(51): {
            exit(0);
        }
        case(52): {
            MenuHelpPlayer();
            break;
        }
        default: {
            SetConsoleCP(1251);
            SetConsoleOutputCP(1251);
            printf("\t\t\t\t\tНеверный символ. Введите символ, указанный левее каждой команды ");
            Sleep(1000);
        }
      }
    }
}