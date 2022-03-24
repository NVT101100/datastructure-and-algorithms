#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <conio.h>
using namespace std;

char hang[8] = { '1','2','3','4','5','6','7','8' };
char cot[8] = { 'a','b','c','d','e','f','g','h' };



struct square
{
public:
    char hang;
    char cot;
}square[8][8];

class chess
{
public: 
    void create(int n)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                square[i][j].hang = hang[i];
                square[i][j].cot = cot[j];
            }
    }
    void display(int n)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                cout << square[i][j].cot << square[i][j].hang << "\t";
            }
            cout << endl << endl;
        }
    }
};

void generateBoard(const int size, vector<string>& board);
void solveBoard(int knightXPos, int knightYPos, vector<string> board);
int calculatePossibleMoves(int nextKnightXPos, int nextKnightYPos, vector<string> board);
bool checkIfCanMove(int nextKnightXPos, int nextKnightYPos, int moveNum, vector<string> board);
const int knightMoves[8][2] = { { 2, 1  }, { 1, 2 }, { -1, 2 }, { -2, 1 }, { -2, -1 }, { -1, -2 }, { 1, -2 }, { 2, -1 } };

int main() {
    int size;
    int xPosition;
    int yPosition;
    vector<string> board;
    cout << "Enter size of a board" << endl;
    cin >> size;
    if (size > 4) {
        generateBoard(size, board);
        cout << "Enter Knight's Y position: ";
        cin >> yPosition;
        cout << "Enter Knight's X position: ";
        cin >> xPosition;
        board[yPosition][xPosition] = 1; //Smiley face
        solveBoard(xPosition, yPosition, board);
        cout << endl;
    }
    else
    {
        cout << "Size of board must be > 4" << endl;
    }
    system("pause");
    return 0;
}
void generateBoard(const int size, vector<string>& board) {
    string stringToAdd;
    board.clear();
    for (int i = 0; i < size; i++) {
        stringToAdd += ' ';
    }
    for (int i = 0; i < size; i++) {
        board.push_back(stringToAdd);
    }
}

void solveBoard(int knightXPos, int knightYPos, vector<string> board) {
    vector<int> moves;
    int smallestNumber = 0;
    int smallestNumberIndex = 0;
    int xMove = 0;
    int yMove = 0;
    chess CHESS;
    CHESS.create(board.size());
    CHESS.display(board.size());
    for (int i = 0; i < board.size() * board.size(); i++) {
        moves.clear();
        for (int j = 0; j < 8; j++) {
            xMove = knightXPos + knightMoves[j][1];
            yMove = knightYPos + knightMoves[j][0];
            if (checkIfCanMove(knightXPos, knightYPos, j, board)) {
                moves.push_back(calculatePossibleMoves(xMove, yMove, board));
            }
            else {
                moves.push_back(-1);
            }
        }
        smallestNumber = 8;
        smallestNumberIndex = 0;
        for (int j = 0; j < moves.size(); j++) {
            if ((moves[j] < smallestNumber) && moves[j] >= 0) {
                smallestNumber = moves[j];
                smallestNumberIndex = j;
            }
        }
        board[knightYPos][knightXPos] = 'X';
        if(i==0) cout << square[knightXPos][knightYPos].cot << square[knightXPos][knightYPos].hang <<"->"<< "\t";
        knightXPos += knightMoves[smallestNumberIndex][1];
        knightYPos += knightMoves[smallestNumberIndex][0];
        board[knightYPos][knightXPos] = 1;
        cout << square[knightXPos][knightYPos].cot << square[knightXPos][knightYPos].hang <<"->"<< "\t";
        
    }
}
int calculatePossibleMoves(int nextKnightXPos, int nextKnightYPos, vector<string> board) {
    int moves = 0;
    for (int i = 0; i < 8; i++) {
        if (checkIfCanMove(nextKnightXPos, nextKnightYPos, i, board)) {
            moves++;
        }
    }

    return moves;
}
bool checkIfCanMove(int nextKnightXPos, int nextKnightYPos, int moveNum, vector<string> board) {
    int xMove = nextKnightXPos + knightMoves[moveNum][1];
    int yMove = nextKnightYPos + knightMoves[moveNum][0];
    if ((xMove >= 0 && xMove < board.size()) && (yMove >= 0 && yMove < board.size()) && board[yMove][xMove] != 'X' && board[yMove][xMove] != 1) {
        return true;
    }
    else {
        return false;
    }
}
