#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <list>
#include <string>
#include <iterator>
#include <sstream>
#include <stack>
#include <vector>

//Constants
/*const int WHITE = 0; //Non visited
const int GREY = 1; //Visited
const int BLACK = 2; //Every son was visited*/
const int NOTIME = 0; //The node hasn't been discovered yet

class Graph{
private:
  int _v;
  std::list<int>* _adjList;
  //int* _visitedNodes;
  std::stack<int>* _stack;
  bool* _inStack;
  int* _discTime;
  int* _low;
public:
  Graph(const int v);
  ~Graph();
  void addVertex(const int v, const int u);
  void visit(const int ind, int *_ptrTime, int *_ptrCount);
  void toString();
};

#endif
