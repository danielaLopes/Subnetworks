#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <list>
#include <string>
#include <iterator>
#include <sstream>
#include <stack>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

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
  std::vector<int> _parents;
  int* _fromSCC;
  std::vector<int> _bridgePairs;
public:
  Graph(const int v);
  ~Graph();
  int getDiscTime(int index);
  void addVertex(const int v, const int u);
  void visit(const int ind, int *_ptrTime, int *_ptrCount, int *_ptrBridges);
  //int compare(const void *ptr1, const void *ptr2);
  void orderBridges(int *_ptrBridges);
  void toString();
};

#endif
