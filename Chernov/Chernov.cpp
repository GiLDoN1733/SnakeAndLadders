#include "Header.h"
#include "HeaderFront.h"
using namespace std;
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