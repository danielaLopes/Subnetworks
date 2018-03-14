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
const int NOTIME = 0; //The node hasn't been discovered yet

class Graph{
private:
  int _v;
  std::list<int>* _adjList;
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
