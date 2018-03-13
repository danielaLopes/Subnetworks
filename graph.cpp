/* GRAPH CLASS */

#include "graph.h"

  //Constructor
  Graph::Graph(const int v){
    _v = v;
    _adjList = new std::list<int>[v];
    _time = 0;
    _count = 0;
    //_visitedNodes = new int[v];
    //for(int i = 0; i < v; i++){
    //  _visitedNodes[i] = WHITE;
    //}
  }

  //Destructor
  Graph::~Graph(){
    for(int i = 0; i < _v; i++){
      _adjList[i].clear();
    }
    delete[] _adjList;
    //delete[] _visitedNodes;
    delete[] _stack;
  }

  //Initialize stacks
  void Graph::initializeStacks(){
      _inStack = new bool[_v];
      _stack = new std::stack<int>[_v];
      _discTime = new int[_v];
      _low = new int[_v];
      for(int i = 0; i < _v; i++){
        _inStack[i] = false;
        _discTime[i] = NOTIME;
        _low[i] = NOTIME;
      }
  }

  void Graph::addVertex(const int v, const int u){
    _adjList[v-1].push_back(u-1); //the positions of the vertexes are always vertex-1
  }

//Tarjan's visit algorithm
  void Graph::visit(const int ind){
    _discTime[ind] = _low[ind] = _time++;
    _stack.push(ind+1); //Stack - vertexes are named ind + 1
    _inStack[ind] = true;
    //_visitedNodes[ind] = GREY;
    std::list<int>::iterator it;
    //visiting adjacent vertexes
    for(it = _adjList[ind].begin(); it!= _adjList[ind].end(); ++it){
      int adjVertex = *it;
      //visit unvisited adjacent vertex
      if(_discTime[adjVertex] == NOTIME){
        visit(adjVertex);
        _low[ind] = min(_low[ind], _low[adjVertex]); //update low value
      }
      //the vertex was already visited
      else if(_inStack[ind] == _discTime[adjVertex]){
        _low[ind] = min(_low[ind], _discTime[adjVertex]); //update low value
      }

      //if(_visitedNodes[*it] == WHITE){
        //visit(*it);
      //}
      //ver else
    //}
    //_visitedNodes[ind] = BLACK;
  }
  //root of a SCC found
  if(_low[ind] == _discTime[ind]){
    int j = 0;
    while(_stack.top() != ind){
      j = (int) _stack.top();
      _inStack[j] = false;
      _stack.pop();
    }
    _count++;
    _inStack[j] = false;
    _stack.pop();
  }
}



  void Graph::toString(){
    for(int i = 0; i < _v; i++){
      std::cout << &_adjList[i] << std::endl;
    }
  }
