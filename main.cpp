#include <iostream>

#include <cstdlib>



using namespace std;



const int rows = 6;

const int columns = 7;



struct Player {

    string name = "Player1";

    char symbol;

    bool isAI = false;

    int wins = 0;

};



Player player1;

Player player2;



Player initializePlayer(char symbol, int number = 1, bool isAI = false) {

    Player player;

    player.symbol = symbol;

    player.isAI = isAI;

    player.wins = 0;

    if (!isAI) {

        cout << "Enter your name: ";

        cin >> player.name;

    }

    else {

        player.name = "AI";

    }

    return player;

}



void drawBoard(char board[rows][columns], bool clearScreen = true) {

    if (clearScreen)

        system("cls");



    cout << "  1    2    3    4    5    6    7" << endl;

    for (int r = 0; r < rows; r++) {

        for (int c = 0; c < columns; c++) {

            if (board[r][c] == 'X')

                cout << "[ " << "\033[31m" << board[r][c] << "\033[0m" << " ]";

            else if (board[r][c] == 'O')

                cout << "[ " << "\033[33m" << board[r][c] << "\033[0m" << " ]";

            else

                cout << "[   ]";

        }

        cout << endl;

    }

}



void putCoin(char board[rows][columns], Player player) {

    int column;

    cout << player.name << "'s turn. Enter column (1-7) to drop your coin: ";

    cin >> column;

    column -= 1;

    for (int r = rows - 1; r >= 0; r--) {

        if (board[r][column] == ' ') {

            board[r][column] = player.symbol;

            return;

        }

    }

    cout << "Column is full! Try a different column." << endl;

    putCoin(board, player);

}



bool isBoardFull(char board[rows][columns]) {

    for (int c = 0; c < columns; c++) {

        if (board[0][c] == ' ') {

            return false;

        }

    }

    return true;

}



bool checkWinCondition(char board[rows][columns], char symbol) {

    // Horizontal

    for (int r = 0; r < rows; r++) {

        for (int c = 0; c < columns - 3; c++) {

            if (board[r][c] == symbol &&

                board[r][c + 1] == symbol &&

                board[r][c + 2] == symbol &&

                board[r][c + 3] == symbol)

                return true;

        }

    }

    // Vertical

    for (int r = 0; r < rows - 3; r++) {

        for (int c = 0; c < columns; c++) {

            if (board[r][c] == symbol &&

                board[r + 1][c] == symbol &&

                board[r + 2][c] == symbol &&

                board[r + 3][c] == symbol)

                return true;

        }

    }

    // Diagonal down-right

    for (int r = 0; r < rows - 3; r++) {

        for (int c = 0; c < columns - 3; c++) {

            if (board[r][c] == symbol &&

                board[r + 1][c + 1] == symbol &&

                board[r + 2][c + 2] == symbol &&

                board[r + 3][c + 3] == symbol)

                return true;

        }

    }

    // Diagonal up-right

    for (int r = 3; r < rows; r++) {

        for (int c = 0; c < columns - 3; c++) {

            if (board[r][c] == symbol &&

                board[r - 1][c + 1] == symbol &&

                board[r - 2][c + 2] == symbol &&

                board[r - 3][c + 3] == symbol)

                return true;

        }



    }

    return false;

}



int main() {

    cout << ">> Welcome to Connect Four!" << endl;

    cout << "Choose game mode ('p' for player vs player, 'a' for player vs AI):" << endl;

    char gameMode;

    cin >> gameMode;



    if (gameMode == 'p') {

        cout << "Player vs Player mode selected." << endl;

        player1 = initializePlayer('X', false);

        player2 = initializePlayer('O', false);

    }

    else if (gameMode == 'a') {

        cout << "Not Yet Implemented" << endl;

        return 1;

    }



    char board[rows][columns];

    for (int r = 0; r < rows; r++) {

        for (int c = 0; c < columns; c++) {

            board[r][c] = ' ';

        }

    }



    drawBoard(board);

    while (true) {

        putCoin(board, player1);

        drawBoard(board);

        if (checkWinCondition(board, player1.symbol) == 1) {

            cout << player1.name << " wins!" << endl;

            player1.wins++;

            break;

        }

        if (isBoardFull(board)) {

            cout << "It's a draw! Board is full!" << endl;

            break;

        }

        putCoin(board, player2);

        drawBoard(board);

        if (checkWinCondition(board, player2.symbol) == 1) {

            cout << player2.name << " wins!" << endl;

            player2.wins++;

            break;

        }

        if (isBoardFull(board)) {

            cout << "It's a draw! Board is full!" << endl;

            break;

        }

    }



    return 0;

} 

