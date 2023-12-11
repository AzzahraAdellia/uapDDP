#include <iostream>
#include <ncurses/ncurses.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>

using namespace std;

const int BOARD_SIZE = 3;

void printBoard(char board[BOARD_SIZE][BOARD_SIZE]);
void makeMove(char board[BOARD_SIZE][BOARD_SIZE], char move);
void makeComputerMove(char board[BOARD_SIZE][BOARD_SIZE], char move);  // Declare makeComputerMove function
bool checkWin(char board[BOARD_SIZE][BOARD_SIZE], char player);
bool isBoardFull(char board[BOARD_SIZE][BOARD_SIZE]);
void clearBoard(char board[BOARD_SIZE][BOARD_SIZE]);
void loading();
void displayWinner(char player);
void waitForInput();

int main() {
    loading();
    srand(time(nullptr));

    char board[BOARD_SIZE][BOARD_SIZE];
    bool playing = true;
    int xWins = 0, oWins = 0;
    char playAgain;

    while (playing) {
    	cout << "Choose the game mode:" << endl;
        cout << "1. Player vs Player" << endl;
        cout << "2. Player vs Computer" << endl;
        cout << "Enter 1 or 2: ";
        
        int choice;
        cin >> choice;
        clearBoard(board);
        printBoard(board);

        char currentPlayer = 'X';
        bool game = true;

         while (game) {
            if (choice == 1) {
                makeMove(board, currentPlayer);
            } else {
                if (currentPlayer == 'X') {
                    makeMove(board, currentPlayer);
                } else {
                    makeComputerMove(board, currentPlayer);
                }
            }

            printBoard(board);

            if (checkWin(board, currentPlayer)) {
                displayWinner(currentPlayer);
                game = false;
                currentPlayer == 'X' ? xWins++ : oWins++;
                break;
            }

            if (isBoardFull(board)) {
                cout << "Seri!" << endl;
                game = false;
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

        cout << "X menang " << xWins << " kali dan O menang " << oWins << " kali. Apakah kamu ingin bermain lagi? (y/n): ";
        cin >> playAgain;

        if (playAgain != 'y' && playAgain != 'Y') {
            playing = false;
        }
    }

    return 0;
}

void clearBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    system("clear"); 
    cout << "  1 2 3" << endl;
    for (int i = 0; i < BOARD_SIZE; i++) {
        char rowLabel = static_cast<char>('a' + i);
        cout << rowLabel << " ";
        for (int j = 0; j < BOARD_SIZE; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void makeMove(char board[BOARD_SIZE][BOARD_SIZE], char move) {
    int row, col;
    cout << "Input baris dan kolom (contoh: a1): ";
    char input[2];
    cin >> input;

    row = input[0] - 'a';
    col = input[1] - '1';

    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != ' ') {
        cout << "Invalid move! Coba lagi." << endl;
        makeMove(board, move);
    } else {
        board[row][col] = move;
    }
}

void makeComputerMove(char board[BOARD_SIZE][BOARD_SIZE], char move) {
    int row, col;
    do {
        row = rand() % BOARD_SIZE;
        col = rand() % BOARD_SIZE;
    } while (board[row][col] != ' ');

    board[row][col] = move;
}

bool checkWin(char board[BOARD_SIZE][BOARD_SIZE], char player) {
    int count = 0;

    for (int a = 0; a < BOARD_SIZE; a++) {
        count = 0;
        for (int b = 0; b < BOARD_SIZE; b++) {
            if (board[a][b] == player) {
                count++;
            }
        }
        if (count == 3) {
            return true;
        }
    }

    for (int a = 0; a < BOARD_SIZE; a++) {
        count = 0;
        for (int b = 0; b < BOARD_SIZE; b++) {
            if (board[b][a] == player) {
                count++;
            }
        }
        if (count == 3) {
            return true;
        }
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }

    if (board[2][0] == player && board[1][1] == player && board[0][2] == player) {
        return true;
    }

    return false;
}

bool isBoardFull(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void loading() {
    system("color B");
    initscr();
    for (int y = 0; y < 3; y++) {
        mvprintw(2, 55, "WELCOME BACK");
        mvprintw(15, 55, "Loading...");
        mvprintw(17, 50, "--------------------");
        mvprintw(18, 50, "|                  |");
        mvprintw(19, 50, "--------------------");
        for (int f = 1; f < 17; f++) {
            mvprintw(18, 50 + f, "<3");
            refresh();
            usleep(30000);  
        }
        for (int a = 1; a < 2; a++) {
            mvprintw(21, 55 + a, "HAVE FUN!");
            refresh();
            usleep(50000);  
        }
    }
    endwin();
}

void displayWinner(char player) {
    cout << "SELAMAT! " << player << " MENANG!" << endl;
    waitForInput();
}

void waitForInput() {
    cout << "Press any key to continue...";
    cin.ignore(); 
    cin.get();    
}

