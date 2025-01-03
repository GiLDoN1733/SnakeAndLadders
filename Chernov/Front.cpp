
#include "HeaderFront.h"
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
int player1 = 0,player2 =0;
void SetPos(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
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
                else if (iterLR % 10 == 0)
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
                else if (iterLR != player2 && iterLR != player1) {
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
            if (iterRL % 10 == 0) {
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
    else if (player1 == 0 && player2 != 0) {
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
    SetPos(60, 25);
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
    SetPos(60, 25);
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
    SetPos(60, 25);
    system("PAUSE");
}
void MenuHelpPlayer() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("cls");
    printf("\n\n\n\n\n\n\n");
    printf("\t\t\t Правила игры:\n\n");
    printf("\t\t\t    В начале игры ( Player vs Player; Player vs Computer) за полем находятся два игрока.\n");
    printf("\t\t\t В начале хода, каждый игрок бросает кубик, значения которого находятся от 1 до 6. Выпавшее число, будет указывать\n");
    printf("\t\t\t на то количество клеток, которое он должен пропустить. После хода перовго игрока происходит ход вторго игрока\n");
    printf("\t\t\t На поле присутствуют клетки, сверху помеченные как Змея и Лестница . При переходе на клетку со змеёй,\n");
    printf("\t\t\t игрок должен перейти на клетку указанную сверху нумерации клетки.\n");
    printf("\t\t\t Пример: запись Змеи:\x1b[31m71>>38\x1b[0m обозначает что игрок с 71 клетки\n");
    printf("\t\t\t игрок должен перейти на 38 клетку, аналогично запись Лестницы:\x1b[32m 65>>88\x1b[0m.\n");
    printf("\t\t\t Конец игры наступает когда один из игроков достигает конечной клетки (100).\n");
    printf("\t\t\t Если игрок находится за одну клетку до финиша и выбрасывает число при котором\n");
    printf("\t\t\t сумма текущей позиции и выброшенного числа больше номера конечной клетки,\n");
    printf("\t\t\t то игрок пропускает ход.\n\n");
    printf("\t\t\t\t\tПриятной игры.\n\n");
    SetPos(60, 25);
    system("PAUSE");
}