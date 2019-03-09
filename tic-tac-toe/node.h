#include "board.h"
#include <vector>
using namespace std;


class Node {
public:
  Board *data;
  vector<Node*> children;
  int score;
  public:
    Node();
    Node(Board*);
    void setData(Board *data1); //setter for data
    void addChild(Board *board); 
    Board* getData();
    vector<Node*>* getChildren();
    void setScore(int);
    int getScore();
    
};
