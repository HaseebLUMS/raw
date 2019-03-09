#include <iostream>
#include "tree.h"
#include <unistd.h>
unsigned int sleep(unsigned int seconds);

using namespace std;

/*#####################################################################################################
  ### 1) This approach is not very optimized solution as it takes more memory relative to output    ###
  ###    given.                                                                                     ###
  ### 2) This is very dry game, dry in a context that it just follow simple winning conditions or   ###
  ###    blocking conditions for winning or drawing.                                                ###
  ### 3) It does not make crispy cases in which opponent get defeated by tricks.                    ###
  #####################################################################################################
  ### Minimax approach will not very effictive in high order TicTacToe as in those cases there will ###
  ### be very ambivalency in picking high score boards for moving towards winning conditions.       ###
  #####################################################################################################
  ### Any approach of making complex cases for users by dynamic score setting while run time, will  ###
  ### be way better and effictive one rather than just following pre-set scores for winning. Such a-###
  ### n approach is of Beta algorithms.                                                             ###
  #####################################################################################################
*/
int main() {
   cout<<"WELCOME TO MYSTERIOUS WORLD OF TIC-TAC-TO!"<<endl;
   Tree* tree = new Tree;
   tree->generateTicTacToe(9);
   tree->minmax_score();
   // first move
   tree->printCurrentState();
   while((tree->getCurrentState()->checkWin() )== 0 && (tree->getCurrentState()->checkDraw() == 0))
   {
      Board* board = new Board(*(tree->getCurrentState()));
      //board->printBoard();
      board->setPlayer(2);
     // cout<<"ye"<<(tree->getCurrentState()->checkWin() )<<endl;
      here:
      int a,b;cout<<"Enter :"; cin>>a>>b; 
      // if(isdigit(a)==1 || isdigit(b)==1)
      // {
      //   cout<<"Enter coordinates jani"<<endl;
      //   goto here;
      // }
      if(board->isValidMove(a,b) == 0)
      {
        cout<<"wrong move, try again."<<endl;
        goto here;
      }
      board->makeMove(a,b);
      tree->updateCurrentState(*board);
      tree->printCurrentState();
      if((tree->getCurrentState()->checkDraw()) == 1)
      {
        // cout<<"hello"<<endl;
         break;
      }
      if((tree->getCurrentState()->checkWin()) == 2)
      {
        // cout<<"hello"<<endl;
         break;
      }
     // cout<<"ye"<<(tree->getCurrentState()->checkWin() )<<endl;
      cout<<"AI making move"<<endl;//cout<<"."<<endl;sleep(1);cout<<"."<<endl;
      //sleep(1);cout<<"."<<endl; sleep(1);
      tree->makeMove();
      tree->printCurrentState();
    //  cout<<"ye"<<(tree->getCurrentState()->checkWin() )<<endl;
     // tree->printCurrentState();
    //  cout<<"ye"<<(tree->getCurrentState()->checkWin() )<<endl;
   }
   if((tree->getCurrentState()->checkWin() )== 1)
   {
      cout<<"You Loser"<<endl;
   }
   else if((tree->getCurrentState()->checkWin() )== 2)
   {
      cout<<"Some INternal Error.. "<<endl;
   }
   else
   {
      cout<<"Draw"<<endl;
   }
   
  return 0;
}
