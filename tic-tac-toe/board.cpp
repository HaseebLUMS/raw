#include <iostream>
#include <cmath>
#include "board.h"

using namespace std;
char Board::val_to_show(int ind)
{
  if(ind == 1){return 'O';}
  if(ind == 2){return 'X';}
  if(ind == 0){return ' ';}
  else return 'q';
}
Board::Board()
{
  currentPlayer = 1; // 1 means AI agent fuck yeah
  dimension = 3;
  board = new int*[3];
  for(int i=0; i< 3; i++)
  {
    board[i] = new int[3];
  }
  for(int i=0; i<3; i++)
  {
    for(int k=0; k< 3; k++)
    {
      board[i][k] =0;
    }
  }
}
Board::Board(int nth)
{
  dimension = nth;
  board = new int*[nth];
  for(int i=0; i< nth; i++)
  {
    board[i] = new int[nth];
  }
  for(int i=0; i<3; i++)
  {
    for(int k=0; k< 3; k++)
    {
      board[i][k] =0;
    }
  }
}
void Board::printBoard()
{
  // ofstream file;
  // file.open("treee.txt");
  cout<< endl<<endl;
  string vel = "                    ";
  for(int i=0; i<dimension; i++)
  {
      cout<<vel;cout<<"    |       |    "<<endl;

    cout<<vel;cout<< val_to_show(board[i][0]) <<"   |   "<< val_to_show(board[i][1])<<"   |   "<<val_to_show(board[i][2])<<endl;
    if(i!= 2)
    {
      cout<<vel;cout<<"____|_______|____"<<endl;
    }
    else
    {
      cout<<vel;cout<<"    |       |    "<<endl;
    }

  }

  cout<<endl<<endl;
}
//void makeMove(int row, int col); // update the board
void Board::makeMove(int row, int col)
{
  here:
  int c=0;
  if(row >= dimension || col >= dimension || row<0 || col< 0)
  {
    cout<<"Wrong move"<<endl;
  }
  vector<pair<int,int> > v_vec = this->getValidMoves();
  for(int i=0; i<tot_mov;i++)
  {
    if(row == v_vec[i].first && col == v_vec[i].second)
    {
      c++;
    }
  }
if(c>0)
{
  if(currentPlayer == 1)
  {
    board[row][col] = 1;
   // printBoard();
  }
  if(currentPlayer == 2)
  {
    board[row][col] = 2;
   // printBoard();
  }
}
else return;
}
void Board::setPlayer(int player_num)
{
  if(player_num == 1 || player_num ==2)
  {
    currentPlayer = player_num;
    return;
  }
  else
    cout<<"Invalid Player."<<endl;
}
void Board::setData(int xCod, int yCod, int dat)
{
  board[xCod][yCod] = dat;
}
int Board::checkWin()
{
     if (board[0][0] == board[0][1] && board[0][0] == board[0][2] && (board[0][0] != 0)){return board[0][0];}
     if (board[1][0] == board[1][1] && board[1][0] == board[1][2]&& (board[1][0] != 0)){return board[1][0];}
     if (board[2][0] == board[2][1] && board[2][0] == board[2][2]&& (board[2][0] != 0)){return board[2][0];}

     if (board[0][0] == board[1][0] && board[0][0] == board[2][0]&& (board[0][0] != 0)){return board[0][0];}
     if (board[0][1] == board[1][1] && board[0][1] == board[2][1]&& (board[0][1] != 0)){return board[0][1];}
     if (board[0][2] == board[1][2] && board[0][2] == board[2][2]&& (board[0][2] != 0)){return board[0][2];}

     if (board[0][0] == board[1][1] && board[0][0] == board[2][2]&& (board[0][0] != 0)){return board[0][0];}
     if (board[0][2] == board[1][1] && board[0][2] == board[2][0]&& (board[0][2] != 0)){return board[0][2];}

  return 0;
}
 //pair<int,int> input(); //take input from user
pair<int,int> Board::input()
{
  cout<<"Enter : ";
  pair<int, int>pair_4_in;
  cin>> pair_4_in.first;
  cin>> pair_4_in.second;
  return pair_4_in;
}
 //int isValidMove(int row, int col);
int Board::isValidMove(int row, int col)
{
  if(row>= dimension ||col>= dimension || row< 0 || col<0)
  {
    return 0;
  }
  if(board[row][col] == 0)
  {
    return 1;
  }
    return 0;
}
//vector<pair<int, int> > getValidMoves();
vector<pair<int,int> > Board::getValidMoves()
{
  tot_mov=0;
  std::vector<pair<int,int> > vec;
  for(int i=0; i<dimension; i++)
  {
    for(int j=0; j< dimension; j++)
    {
      if(board[i][j]==0)
      {
        pair<int,int> pair1 (i,j);
        tot_mov++;
        vec.push_back(pair1);

      }
    }
  }

  return vec;
}
int Board::checkDraw()
{
  int con = 0;
  for(int i=0; i< dimension; i++)
  {
    for(int j=0; j< dimension; j++)
    {
      if(board[i][j] == 0)
      {
        con++;
      }
    }
  }

  if(con> 0)
  {
    return 0;
  }

  int dr = checkWin();
  if(dr == 0 )
  {
    //cout<<"here fuck"<<endl;
    return 1;
  }
  return 0;
}
Board::Board(Board& b2)
{
  //board = b2.board;
  board = new int*[b2.dimension];
  dimension = b2.dimension;
  for(int i=0; i< dimension; i++)
  {
    board[i] = new int[dimension];
  }
  for(int i=0; i<dimension; i++)
  {
    for(int k=0; k<dimension; k++)
    {
      board[i][k] = b2.board[i][k];
    }
  }


}

bool Board::operator ==(Board &rhs) const
{
  if(rhs.dimension != dimension)
  {
    return false;
  }
  int eq=0;
  for(int i=0; i< dimension; i++)
  {
    for(int k=0; k<dimension; k++)
    {
      if(board[i][k] != rhs.board[i][k])
      {
        eq++;
      }
    }
  }
  //cout<<"DFGRBTHYJUYTHRGEFWDERGTHY6JU"<<endl;
  if(eq != 0)
  {
    return false;
  }
  return true;
}
void Board::operator = (const Board &lhs)
{
  for(int i=0; i< dimension; i++)
  {
    for(int k=0; k< dimension; k++)
    {
      lhs.board[i][k] = board[i][k];
    }
  }
}
