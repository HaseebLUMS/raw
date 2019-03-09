#include <string>
#include "node.h"
#include <iostream>

using namespace std;


class Tree {
public:
  Node *root;
  Node *currentState; //pointer to node in tree with current state
  public:
    Tree();
    int generateTicTacToe(Node* head, int currentDepth, int totalDepth); //part 2
    void generateTicTacToe(int depth); // part 2
    void initCurrentState();
    void minmax_score();
    void minmax(Node* root, int c_depth);
    void updateCurrentState(Board& b);
    void printCurrentState();
    Board* getCurrentState();
    void makeMove(); //move made by AI
    Node* find_by_board(Board* board1, Node* &head);
    int count_nodes(Node* head);
};
