#include <cmath>
#include <algorithm>
#include "tree.h"

using namespace std;
void Tree::initCurrentState()
{
  currentState = root;
}
void Tree::updateCurrentState(Board& b)
{
  //Board* b1 = *b;
  currentState = find_by_board(&b, root);
}
void Tree::printCurrentState()
{
  currentState->getData()->printBoard();
}
Board* Tree::getCurrentState()
{
  return currentState->getData();
}
Tree::Tree()
{
  root = new Node;
  currentState = root;
  //currentState->getData()->printBoard();
}
void Tree::generateTicTacToe(int depth)
{
  depth = 9;
  int x = generateTicTacToe(root, 1, depth);
 root->setScore(x);
// cout<< root->getScore()<<endl;
}
int Tree::generateTicTacToe(Node* head, int currentDepth, int totalDepth)
{
  //head->getData()->printBoard();
  int s_2_return = 0;
  if(currentDepth >10)
  {
    return 0;
  }

  {
    {
      if(head->getData()->checkWin() == 1)
      {
        head->setScore(1000);
        return head->getScore();
      }
      else if(head->getData()->checkDraw())
      {
        head->setScore(200);        
        return head->getScore();
      }
      else if(head->getData()->checkWin() == 2)
      {
        head->setScore(-1000);
        return head->getScore();
      }

    }

  }
  // counting nodes for next level
  int nodes_4_next_level = totalDepth+1 - currentDepth;
  // so now next level's nodes will be created// node means making a board and fedding as addChild to node
  Board* record_board = new Board(*(head->getData()));
  //cout << v1.size()<<endl;//record_board->printBoard();
  int f1=0;
  while(f1 < nodes_4_next_level)
  {
    Board* b = new Board(*(head->getData()));
      //b->printBoard();
    for(int i=0; i< 10; i++)
    {
      for(int k=0; k< 10; k++)
      {
        if(record_board->isValidMove(i,k))
        {
          if(currentDepth % 2)
          {
            b->setPlayer(2);
            b->setData(i,k,2);
          record_board->setData(i,k,2);
          }
          else
          {
            b->setPlayer(1);
            b->setData(i,k,1);
            record_board->setData(i,k,1);
          }

          i = 1000; k=1000;
        }
      }
    }
    head->addChild(b);
    f1++;
  }
  // now calling it recursively for every child
    vector<Node*> vv = *(head->getChildren());
    //cout<<"abc     "<< vv.size()<< "    hbsu"<<endl;// vv[0]->getData()->printBoard();
    for(int i=0; i< vv.size(); i++)
    {
      
       s_2_return += generateTicTacToe(vv[i], currentDepth+1, totalDepth);
    }
    head->setScore(s_2_return);
    return head->getScore();
}
Node* Tree::find_by_board(Board* board1, Node* &head)
 {
  //   if((*(head->getChildren())).size() == 0)
  // {
  //  return NULL;
  // }
  // else
  {
  if((*(head->getData()) == *(board1)) )
  {
  //  cout<<head<<endl;
    return head; 
  }
  //cout << (*(head->getChildren())).size() << endl;
  for(int i=0; i< (*(head->getChildren())).size(); i++  )
  {
  Node* x = find_by_board(board1,(*(head->getChildren()))[i]);
  if(x)
    return x;

  }
  }
//   if( *(head->getData()) == *board1)
//   {
//     return head;
//   }
//   Node* n = head;
//   for(int i=0; i< (n->children).size(); i++ )
//   {
//     if(board1 == (n->children)[i] ->getData())
//     {
//       return (n->children)[i];
//     }
//     else
//     {
//      return find_by_board(board1, (n->children)[i]);
//     }
//   }
}
void Tree::makeMove()
{
  Board* b = this->getCurrentState();
  Node* node = this->find_by_board(b, root);
  vector<Node*> v= *(node->getChildren());
  
  // for(int i=0; i< v.size(); i++)
  // {
  //   v[i]->getData()->printBoard();
  // }

  int max_till = v[0]->getScore();
 // cout<<"a "<< max_till<<endl;
  Node* n2 = v[0];
    for(int k=0; k< v.size(); k++)
    {
      int h1 = (v[k]->getScore());
    //  cout << "h1 score = " << h1 << endl; v[k]->getData()->printBoard();
      if(h1 > max_till)
      {
       // cout<<"Higher " <<h1 << " FRom"<< " max :"<< max_till <<endl;
        max_till = v[k]->getScore();
        n2 = v[k];
      }
    }
    n2->getData()->setPlayer(1);
      for(int i=0; i< v.size(); i++)
      {
        if(v[i]->getData()->checkWin() == 1)
        {
          cout<<"point"<<endl;
          updateCurrentState(*(v[i]->getData()));
          return;
        }
      }
      this->updateCurrentState(*(n2->getData()));
}
// int main()
// {
// 	Tree* t1= new Tree;
// 	t1->generateTicTacToe(9);
// 	cout<<endl;
// 	vector<Node*> v = *(t1->root->getChildren() );

// 	for (int i = 0; i < 9; ++i)
// 	{
// 		cout<<v[i]->getScore()<<endl;
// 		v[i]->getData()->printBoard();
// 	}

// 	std::vector<Node*> v2 = *(v[0] -> getChildren() );

// 	for (int i = 0; i < 8; ++i)
// 	{
// 		cout<<v2[i]->getScore()<<endl;
// 		v2[i]->getData()->printBoard();
// 	}
// 	cout<<"Trouble is here"<<endl;
// 	std::vector<Node*> v3 = *(v2[1] -> getChildren() );

// 	for (int i = 0; i < 7; ++i)
// 	{
// 		cout<<v3[i]->getScore()<<endl;
// 		v3[i]->getData()->printBoard();
// 	}

// 	t1->updateCurrentState(*(v3[2]->getData()));
// 	cout<<"curent state"<<endl;
// 	t1->printCurrentState();
// 	t1->makeMove();
// 	t1->printCurrentState();
// 	// cout<<"Trouble is also here"<<endl;
// 	// std::vector<Node*> v4 = *(v3[2] -> getChildren() );

// 	// for (int i = 0; i < 6; ++i)
// 	// {
// 	// 	cout<<v4[i]->getScore()<<endl;
// 	// 	v4[i]->getData()->printBoard();
// 	// }
	
// 	// // t1->printCurrentState();
// 	// // t1->updateCurrentState(*(v2[7]->getData()));
// 	// // //t1->makeMove();
// 	// // t1->printCurrentState();
// 	return 0;
// }
void Tree::minmax_score()
{
  this->minmax(root, 1);
}
void Tree::minmax(Node* node, int c_depth)
{
  if(c_depth>10)
    return;
  if((*(node->getChildren())).size() == 0)
  {
    if(node->getData()->checkWin() == 1)
    {
      node->setScore(20-c_depth);
      return;
    }
    else if(node->getData()->checkWin() == 2)
    {
      node->setScore(-20+c_depth);
      return;
    }
    else
    {
      node->setScore(0);
      return;
    }
  }
  else
  {
    vector<Node*> v1= *(node -> getChildren());
    for(int i=0; i< v1.size(); i++)
    {
      minmax(v1[i], c_depth+1);

    }
  }
 
    vector<Node*> v= *(node -> getChildren());
    /* finding max */
    // int max = v[0]->getScore();
    // for(int i=0; i< v.size(); i++)
    // {
    //   if(v[i]->getScore() > v[0]->getScore())
    //   {
    //     max = v[i]->getScore();
    //   }
    // }
    // int min = v[0]->getScore();
    // for(int i=0; i< v.size(); i++)
    // {
    //   if(v[i]->getScore() < v[0]->getScore())
    //   {
    //     min = v[i]->getScore();
    //   }
    // }
    vector<int> xx;
    for (int i = 0; i < v.size(); ++i)
    {
      xx.push_back(v[i]->getScore());
    }
    sort(xx.begin(),xx.end());
    reverse(xx.begin(),xx.end());

    if(c_depth % 2 == 1)
    {
      /* set score by
      min as these are
      odd steps i.e 
      human steps*/
      node->setScore(xx[xx.size()-1]);
      return;
    }
    else
    {
      node->setScore(xx[0]);
      return;
    } 
}