// C Program to implement Snake and Ladder Game 
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include<iostream>
using namespace std;
//#include <wchar.h>
// Function to roll a six-sided die 
int rollDie() { return rand() % 6 + 1; }

// global variables to store postions of player1 and player2 
int player1 = 0, player2 = 0;

// Function to print the board 
void printBoard()
{
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

	printf("\n\n\n");
	printf("\t\t\t\t\t\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
	while (val--) {
		if (alt == 0) {
			--iterLR;
			while (iterLR % 10 != 1) {
				
				if (iterLR == 61)
					printf("\t\t\t\t\t\xba\x1b[31m abcde\x1b[0m");
				else if (iterLR == 6 || iterLR == 77)
					printf("\xba\x1b[32m abcde\x1b[0m");
				else if (iterLR == 23 || iterLR == 45 || iterLR == 65 || iterLR == 98)
					printf("\xba\x1b[31m abcde\x1b[0m");
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
						printf("\t\t\t\t\t\xba\x1b[33m #P1P2\x1b[0m");
					}
					else if (iterLR == player1 && iterLR == player2) {
						printf("\xba\x1b[33m#P1P2 \x1b[0m");
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
					printf("\xba\x1b[33m#P1P2 \x1b[0m\xba");
				}
				else if (iterLR == player1 && player1 % 10 == 1) {
					printf("\xba\x1b[34m  #P1 \x1b[0m\xba");
				}
				else if (iterLR == player2 && player2 % 10 == 1) {
					printf("\xba\x1b[36m  #P2 \x1b[0m\xba");
				}

				if (iterLR % 10 == 1) {
					printf("\n\t\t\t\t\t\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xb9\n");
					alt = 1;
					iterLR -= 10;
				}
		}
		else {
			        ++iterRL;
					while (iterRL % 10 != 0) {
						if (iterRL == 61)
							printf("\t\t\t\t\t\xba\x1b[31m abcde\x1b[0m");
						else if (iterRL == 6 || iterRL == 77)
							printf("\xba\x1b[32m abcde\x1b[0m", board[iterRL]);
						else if (iterRL == 23 || iterRL == 45 || iterRL == 61 || iterRL == 65 || iterRL == 98)
							printf("\xba\x1b[31m abcde\x1b[0m", board[iterRL]);
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
							printf("\t\t\t\t\t\xba\x1b[33m #P1P2\x1b[0m");
						}
						else if (iterRL == player1 && iterRL == player2) {
							printf("\xba\x1b[33m #P1P2\x1b[0m");
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
					else if (iterRL == player1 && player1 % 10 == 0) {
						printf("\xba\x1b[34m  #P1 \x1b[0m\xba");
					}
					else if (iterRL == player2 && player2 % 10 == 0) {
						printf("\xba\x1b[36m  #P2 \x1b[0m\xba");
					}
					else if (iterRL == player1 && iterRL % 10 == 0 && iterRL == player2) {
						printf("\xba\x1b[33m  #PP \x1b[0m\xba");
					}
					
			
					
			if (iterRL % 10 == 0 && iterRL != 10) {
				printf("\n\t\t\t\t\t\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xb9\n");
				alt = 0;
				iterRL -= 30;
			}
		}
		if (iterRL == 10)
			break;
	}
	printf("\n");
	printf("\t\t\t\t\t\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xcd\xd9\n\n");


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
	snakesAndLadders[98] = -10;
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
void MainMenuText(void)
{



}
int main()
{
	MainMenuText();

	srand(time(0)); // Initialize random seed 
	int currentPlayer = 1;
	int won = 0;

	printf("Snake and Ladder Game\n");

	while (!won) {

		printf(
			"\nPlayer %d, press Enter to roll the die...",
			currentPlayer);
		getchar(); // Wait for the player to press Enter 
		int roll = rollDie();

		if (currentPlayer == 1) {
			system("cls");
			player1 = movePlayer(player1, roll);
			printBoard();
			printf("Player 1 rolled %d.\n", roll);
			printf("Player 1 is now at square %d.\n\n", player1);
			if (player1 == 100) {
				
				printf("Player 1 wins!\n");
				won = 1;
			}
		}
		else {
			system("cls");
			player2 = movePlayer(player2, roll);
			printBoard();
			printf("Player 2 rolled %d.\n", roll);
            printf("Player 2 is now at square %d.\n\n",player2);
			if (player2 == 100) {
				
				printf("Player 2 wins!\n");
				won = 1;
			}
		}

		// Switch to the other player 
		currentPlayer = (currentPlayer == 1) ? 2 : 1;
	}

	return 0;
}
