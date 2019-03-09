#include "node.h"

using namespace std;

Node::Node()
{
  data = new Board;
  score =0;
}
Node::Node(Board* b)
{
  score = 0;
  data = new Board(*b);
}
void Node::setData(Board *data1)
{
  *data = *data1;
}
void Node::addChild(Board* board)
{
  Node* n = new Node(board);
  //*(n->data) = *board;
  children.push_back(n);
}
Board* Node::getData()
{
  return data;
}
vector<Node*>* Node::getChildren()
{
  std::vector<Node*>* v = &children;
  return v;
}
void Node::setScore(int b)
{
  score = b;
}
int Node::getScore()
{
  return score;
}