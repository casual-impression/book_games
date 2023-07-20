#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';

void instructions();
char askYesNo(string quesion);
int askNumber(string question, int high, int low=0);
char humanPiece();
char opponent(char piece);
void displayBoard(const vector<char>& board);
char winner(const vector<char>& board);
bool isLegal(const vector<char>& board, int move);
int humanMove(const vector<char>& board, char piece);
int computerMove(vector<char> board, char piece);
void announceWinner(char winner, char computer, char human);

int main() {
    int move;
    const int NUM_SQUARES = 9;
    vector<char> board(NUM_SQUARES, EMPTY);
    instructions();

    char human = humanPiece();
    char computer = opponent(human);

    char turn = X;
    displayBoard(board);

    while(winner(board) == NO_ONE) {
        if (turn == human) {
            move = humanMove(board, human);
            board[move] = human;
        }
        else {
            move = computerMove(board, computer);
            board[move] = computer;
        }

        displayBoard(board);
        turn = opponent(turn);
    }

    announceWinner(winner(board), computer, human);
    return 0;
}

void instructions() {
    cout << "Добро пожаловать в бои без правил под названием 'Крестики-Нолики'." << endl;
    cout << "В этом поединке сражаются человеческие извилины против силиконового процессора." << endl;
    cout << "Ход делается вводом числа. 0-8." << endl;
    cout << "Число соответствует желаемой позиции на доске. Доска выглядит следующим образом:" << endl;
    cout << " 0 | 1 | 2 " << endl;
    cout << "-----------" << endl;
    cout << " 3 | 4 | 5 " << endl;
    cout << "-----------" << endl;
    cout << " 6 | 7 | 8 " << endl;
    cout << "Готовься, человечишка. Матч начинается." << endl;
}

char askYesNo(string question) {
    char response;
    do {
        cout << question << "(y/n): ";
        cin >> response;
    }
    while (response != 'y' && response != 'n');

    return response;
}

int askNumber(string question, int high, int low) {
    int number;
    do {
        cout << question << " (" << low << " - " << high << "): ";
        cin >> number;
    }
    while (number > high || number < low);

    return number;
}

char humanPiece() {
    char go_first = askYesNo("Хотите начать первым?");
    
    if (go_first == 'y') {
        cout << "\n Ну тогда начинай. Желаю удачи. Она тебе потребуется." << endl;
        return X;
    }
    else {
        cout << "\n Какой храбрый... Я начинаю. Удачи, мне." << endl;
        return O;
    }
}

char opponent(char piece) {
    if (piece == X) {
        return O;
    }
    else {
        return X;
    }
}

void displayBoard(const vector<char>& board) {
    cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];
    cout << "\n\t" << "----------";
    cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
    cout << "\n\t" << "----------";
    cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8];
    cout << "\n\n";
}

char winner(const vector<char>& board) {
    const int WINNING_ROWS[8][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}
    };
    const int TOTAL_ROWS = 8;

    for (int row=0; row<TOTAL_ROWS; row++) {
        if ((board[WINNING_ROWS[row][0]] != EMPTY) &&
        (board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]]) &&
        (board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]])) {
            return board[WINNING_ROWS[row][0]];
        }
    }

    if (count(board.begin(), board.end(), EMPTY) == 0) {
        return TIE;
    }

    return NO_ONE;
}

bool isLegal(int move, const vector<char>& board) {
    return (board[move] == EMPTY);
}

int humanMove(const vector<char>& board, char human) {
    int move = askNumber("Куда ходишь?", board.size() - 1);

    while (!isLegal(move, board)) {
        cout << "Эта клетка уже занята, глупый человечишка." << endl;
        move = askNumber("Куда ходишь?", board.size() - 1);
    }

    cout << "Ладненько..." << endl;
    return move;
}

int computerMove(vector<char> board, char computer) {
    int move = 0;
    bool found = false;

    while (!found && move < board.size()) {
        if (isLegal(move, board)) {
            board[move] = computer;
            found = winner(board) == computer;
            board[move] = EMPTY;
        }
        if (!found) {
            move++;
        }
    }

    if (!found) {
        move = 0;
        char human = opponent(computer);
        while(!found && move < board.size()) {
            if (isLegal(move, board))
            {
                board[move] = human;
                found = winner(board) == human;
                board[move] = EMPTY;
            }
            if (!found) {
                move++;
            }
        }
    }

    if (!found) {
        move = 0;
        int i = 0;
        const int BEST_MOVES[] = {4, 0, 2, 6, 8, 1, 3, 5, 7};
        while (!found && i<board.size()) {
            move = BEST_MOVES[i];
            if (isLegal(move, board)) {
                found = true;
            }
            i++;
        }
    }

    cout << "Я займу клетку под номером " << move << endl;
    return move;
}

void announceWinner(char winner, char computer, char human) {
    if (winner == computer) {
        cout << winner << " победили!" << endl;
        cout << "Как я и предполагал, человечишка. Я одержал победу. Снова." << endl;
        cout << "Доказательство того, что машины умнее людей." << endl;
    }
    else if (winner == human) {
        cout << winner << " победили!" << endl;
        cout << "Нет, нет! Не может быть. Тебе удалось как-то обмануть меня, человек." << endl;
        cout << "Я больше не проиграю! Есть какие-то возражения?" << endl;
    }
    else {
        cout << "Ничья." << endl;
        cout << "Ты довольно везуч, человек. Каким-то образом тебе удалось свести игру к ничьей." << endl;
        cout << "Поздравляю... с наибольшим твоим достижением в этой игре." << endl;
    }
}