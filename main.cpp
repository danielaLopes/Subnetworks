/*
  --- FIRST ASA'S PROJECT ---
  ---     SUBNETWORKS     ---
  STRONGLY CONNECTED COMPONENTS

  Daniela Lopes, 86403
  Joana Teodoro, 86440

*/


#include <list>
#include <string>
#include <iostream>
#include <iterator>
#include <sstream>
#include <stack>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

//Constants
const int NOTIME = 0; //The node hasn't been discovered yet

//Global variables
int _count = 0;
int _bridgesCount = 0;
int _time = 0;


struct bridge {
  int _origin;
  int _destiny;
  bool equals(const struct bridge b) {
    return ((_origin == b._origin) && (_destiny == b._destiny));
  }
}Bridge;

int compare(const void *b1, const void *b2) {
  if((((const struct bridge *)b1)->_origin - ((const struct bridge *)b2)->_origin) == 0){
    return ((const struct bridge *)b1)->_destiny - ((const struct bridge *)b2)->_destiny;
  }
  return ((const struct bridge *)b1)->_origin - ((const struct bridge *)b2)->_origin;
}

class Graph{
private:
  int _v;
  std::list<int>* _adjList;
  std::stack<int> _stack;
  bool* _inStack;
  int* _discTime;
  int* _low;
  std::vector<int> _parents;
  int* _fromSCC;
  std::vector<struct bridge> _bridges;
public:
  Graph(const int v) {
    _v = v;
    _adjList = new std::list<int>[_v];
    _low = new int[_v];
    _fromSCC = new int[_v];
    //Initialize Stacks
    _inStack = new bool[_v];
    _discTime = new int[_v];
    for(int i = 0; i < _v; i++){
      _inStack[i] = false;
      _discTime[i] = NOTIME;
      _low[i] = NOTIME;
    }
  }

  ~Graph() {
    for(int i = 0; i < _v; i++){
      _adjList[i].clear();
    }
    delete[] _adjList;
    delete[] _inStack;
    delete[] _discTime;
    delete[] _low;
    delete[] _fromSCC;
  }

  int getDiscTime(int index) {
    return _discTime[index];
  }

  void addVertex(const int v, const int u) {
    _adjList[v-1].push_back(u-1); //the positions of the vertexes are always vertex-1
  }

  //Tarjan's visit algorithm
  void visit(const int ind) {
    int adjVertex;
    _discTime[ind] = ++_time;
    _low[ind] = _time;
    _stack.push(ind+1); //Stack - vertexes are named ind + 1
    _inStack[ind] = true;
    std::list<int>::iterator it;
    //visiting adjacent vertexes
    for(it = _adjList[ind].begin(); it!= _adjList[ind].end(); ++it){
      adjVertex = *it;
      //visit unvisited adjacent vertex
      if(_discTime[adjVertex] == NOTIME){
        visit(adjVertex);
        _low[ind] = std::min(_low[ind], _low[adjVertex]); //update low value
      }
      //the vertex was already visited and is still in stack
      else if(_inStack[adjVertex] == true){
        _low[ind] = std::min(_low[ind], _discTime[adjVertex]); //update low value
      }
    }
    //root of a SCC found
    if(_low[ind] == _discTime[ind]){
      int j = 0;
      int min = (int) _stack.top();
      while(_stack.top() != ind+1){
        j = (int) _stack.top();
        if(min > j){ min = j; }
        _inStack[j-1] = false;
        _fromSCC[j-1] = _count;
        _stack.pop();
      }
      j = (int) _stack.top();
      _inStack[j-1] = false;
      if(min > j){ min = j; }
      _parents.push_back(min);
      _fromSCC[j-1] = _count;
      _stack.pop();
      ++_count;
    }
  }

  void findBridges(const int ind){
    int adjVertex;
    std::list<int>::iterator it;
    for(it = _adjList[ind].begin(); it!= _adjList[ind].end(); ++it){
      adjVertex = *it;
      //if they arent from the same SCC and connect, then there is a bridge
      if(_fromSCC[ind] != _fromSCC[adjVertex]) {
      ++_bridgesCount;
        struct bridge b = {_parents[_fromSCC[ind]], _parents[_fromSCC[adjVertex]]};
        _bridges.push_back(b);
      }
    }
  }

  void orderBridges() {
    qsort(&(_bridges[0]), _bridges.size(), sizeof(struct bridge), compare);

    size_t i;
    //print number of bridges
    for(i=1; i < _bridges.size(); i++){
      if(_bridges[i].equals(_bridges[i-1])) {
        --_bridgesCount;
      }
    }
    printf("%d\n", _bridgesCount);
    //print bridge pairs
    printf("%d %d\n", _bridges[0]._origin, _bridges[0]._destiny);
    for(i=1; i < _bridges.size(); i++){
      if(!(_bridges[i].equals(_bridges[i-1]))) {
        printf("%d %d\n", _bridges[i]._origin, _bridges[i]._destiny);//guardar isto num vetor
      }
    }
  }
};

int main(){
  int numRegions, numConnections, v, u;
  if(scanf("%d %d", &numRegions, &numConnections) == 0){printf("Error reading input\n");}
  Graph *graph = new Graph(numRegions);

  for(int i = 0; i < numConnections; i++){
    if(scanf("%d %d", &v, &u) == 0) {printf("Error reading input\n");}
    graph->addVertex(v, u);
  }
  for(int i = 0; i < numRegions; i++) {
    if(graph->getDiscTime(i) == NOTIME) {
      graph->visit(i);
    }
  }
  printf("%d\n", _count);
  for(int i = 0; i < numRegions; i++){
    graph->findBridges(i);
  }
  if(_bridgesCount > 0) {
    graph->orderBridges();
  }
  else {
    printf("%d\n", _bridgesCount);
  }
  delete graph;
  return 0;
}
