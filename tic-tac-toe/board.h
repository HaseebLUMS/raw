#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Board {

  //3x3 board
  int **board;
  int currentPlayer;
  
  int dimension; // dimensions of game. For our purpose, this will always be 3 as we are working with a 3x3 board

  public:
    int tot_mov;
    Board(); // Done######
    Board(int); //Done#####
    void makeMove(int row, int col); //Done###### // update the board
    int checkWin(); //Done###### // checks if someone has won the game
    pair<int,int> input(); //Done########//take input from user
    void printBoard(); // Done#########
    int isValidMove(int row, int col);//Done######
    vector<pair<int, int> > getValidMoves(); //Done###### //get list of all possible valid moves
    int checkDraw();//DOne######
    void setData(int, int, int);//Done######### //update a particular value on the board directly instead of making a move
    Board(Board&); // Done####
    bool operator ==(Board &rhs) const; //Done######
    void operator = (const Board &lhs); // Done########
    void setPlayer(int); // Done######
    char val_to_show(int ind); //Done######
    int getDim() { return dimension;}
    int** getBoard()
    {
      return board;
    }
};
