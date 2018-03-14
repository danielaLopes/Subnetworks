/* GRAPH CLASS */

#include "graph.h"

  //Constructor
  Graph::Graph(const int v){
    _v = v;
    _adjList = new std::list<int>[_v];
    //Initialize Stacks
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

  //Destructor
  Graph::~Graph(){
    for(int i = 0; i < _v; i++){
      _adjList[i].clear();
    }
    delete[] _adjList;
    delete[] _inStack;
    delete[] _discTime;
    delete[] _low;
    delete[] _stack;
  }

  void Graph::addVertex(const int v, const int u){
    _adjList[v-1].push_back(u-1); //the positions of the vertexes are always vertex-1
  }

//Tarjan's visit algorithm
  void Graph::visit(const int ind, int *_ptrTime, int *_ptrCount){
    int adjVertex;
    _discTime[ind] = ++*(_ptrTime);
    _low[ind] = *(_ptrTime);
    _stack->push(ind+1); //Stack - vertexes are named ind + 1
    _inStack[ind] = true;
    std::list<int>::iterator it;
    //visiting adjacent vertexes
    for(it = _adjList[ind].begin(); it!= _adjList[ind].end(); ++it){
      adjVertex = *it;
      //visit unvisited adjacent vertex
      if(_discTime[adjVertex] == NOTIME){
        visit(adjVertex, _ptrTime, _ptrCount);
        _low[ind] = std::min(_low[ind], _low[adjVertex]); //update low value
        if(_low[adjVertex] > _discTime[ind]){
          std::cout << ind+1 << " " << adjVertex+1 << std::endl; //finding right path of bridge
        }
      }
      //the vertex was already visited
      else if(_inStack[adjVertex] == true){
        _low[ind] = std::min(_low[ind], _discTime[adjVertex]); //update low value
      }
    }
    //root of a SCC found
    if(_low[ind] == _discTime[ind]){
      int j = 0;
      while(_stack->top() != ind+1){
        j = (int) _stack->top();
        _inStack[j-1] = false;
        _stack->pop();
      }
      _inStack[j-1] = false;
      _stack->pop();
      ++*_ptrCount;
    }
}

  void Graph::toString(){
    for(int i = 0; i < _v; i++){
      std::cout << &_adjList[i] << std::endl;
    }
  }
