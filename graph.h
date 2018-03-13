#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <list>
#include <string>
#include <iterator>
#include <sstream>
#include <stack>

//Constants
/*const int WHITE = 0; //Non visited
const int GREY = 1; //Visited
const int BLACK = 2; //Every son was visited*/
const int NOTIME = -1; //The node hasn't been discovered yet

class Graph{
private:
  int _v;
  static int _time;
  static int _count;
  std::list<int>* _adjList;
  //int* _visitedNodes;
  std::stack<int> _stack;
  bool* _inStack;
  int *_discTime;
  int* _low;
public:
  Graph(const int v);
  ~Graph();
  void initializeStacks();
  void addVertex(const int v, const int u);
  void visit(const int ind);
  void toString();
};

#endif
