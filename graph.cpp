/* GRAPH CLASS */

#include "graph.h"

  std::vector< std::vector<int> > _sccs(100); //APAGAR
  std::vector<int> bridges;

  //Constructor
  Graph::Graph(const int v){
    _v = v;
    _adjList = new std::list<int>[_v];
    _low = new int[_v];
    _fromSCC = new int[_v];
    //Initialize Stacks
    _inStack = new bool[_v];
    _stack = new std::stack<int>[_v];
    _discTime = new int[_v];
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
    delete[] _fromSCC;
<<<<<<< HEAD
  }

  int Graph::getDiscTime(int index) {
    return _discTime[index];
=======
>>>>>>> 1c77a60ae6f4285e408060f00d6282f47bcd1181
  }

  void Graph::addVertex(const int v, const int u){
    _adjList[v-1].push_back(u-1); //the positions of the vertexes are always vertex-1
  }

  /*int Graph::compare(const void *ptr1, const void *ptr2){
    return (*(int*)ptr1 - *(int*)ptr2);
  }*/

//Tarjan's visit algorithm
  void Graph::visit(const int ind, int *_ptrTime, int *_ptrCount, int *_ptrBridges){
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
        visit(adjVertex, _ptrTime, _ptrCount, _ptrBridges);
        _low[ind] = std::min(_low[ind], _low[adjVertex]); //update low value
<<<<<<< HEAD
        //finding bridges
=======
>>>>>>> 1c77a60ae6f4285e408060f00d6282f47bcd1181
        if(_low[adjVertex] > _discTime[ind]){
          _bridgePairs.push_back(ind+1);
          _bridgePairs.push_back(adjVertex+1);
          ++*_ptrBridges;
<<<<<<< HEAD
        }
      }
      //the vertex was already visited and is still in stack
      else if(_inStack[adjVertex] == true){
        _low[ind] = std::min(_low[ind], _discTime[adjVertex]); //update low value
      }
      //the vertex was already visited but is out of stack, which means it belongs to a different scc
      //finding other connecting paths
      else if(_discTime[adjVertex] != NOTIME) {
        _bridgePairs.push_back(ind+1);
        _bridgePairs.push_back(adjVertex+1);
        ++*_ptrBridges;
=======
          //std::cout << ind+1 << " " << adjVertex+1 << std::endl; //finding right path of bridge
        }
      }
      //the vertex was already visited
      else if(_inStack[adjVertex] == true){
        _low[ind] = std::min(_low[ind], _discTime[adjVertex]); //update low value
>>>>>>> 1c77a60ae6f4285e408060f00d6282f47bcd1181
      }
    }
    //root of a SCC found
    if(_low[ind] == _discTime[ind]){
      int j = 0;
      int min = (int) _stack->top();
      while(_stack->top() != ind+1){
        j = (int) _stack->top();
        if(min > j){ min = j; }
        _inStack[j-1] = false;
        _sccs[*_ptrCount].push_back(j);
        _fromSCC[j-1] = *_ptrCount;
        _stack->pop();
<<<<<<< HEAD
      }
      j = (int) _stack->top();
      _inStack[j-1] = false;
      if(min > j){ min = j; }
      _parents.push_back(min);
      _sccs[*_ptrCount].push_back(j);
      _fromSCC[j-1] = *_ptrCount;
      _stack->pop();
      //bridges.push_back(_parents[_fromSCC[_bridgePairs[0]-1]]*10 + _parents[_fromSCC[_bridgePairs[1]-1]]);
      //APAGAR DEPOIS
      /*for(int k = 0; k < _sccs[*_ptrCount].size(); k++){
        std::cout << _sccs[*_ptrCount][k] << " SCCs" << std::endl;
      }
=======
      }
      j = (int) _stack->top();
      _inStack[j-1] = false;
      if(min > j){ min = j; }
      _parents.push_back(min);
      _sccs[*_ptrCount].push_back(j);
      _fromSCC[j-1] = *_ptrCount;
      _stack->pop();
      //bridges.push_back(_parents[_fromSCC[_bridgePairs[0]-1]]*10 + _parents[_fromSCC[_bridgePairs[1]-1]]);
      //APAGAR DEPOIS
      /*for(int k = 0; k < _sccs[*_ptrCount].size(); k++){
        std::cout << _sccs[*_ptrCount][k] << " SCCs" << std::endl;
      }
>>>>>>> 1c77a60ae6f4285e408060f00d6282f47bcd1181
      for(int k = 0; k < _v; k++){
        printf("%d\n", _fromSCC[k]);
      }*/

      ++*_ptrCount;
    }
  }

  void Graph::toString(){
    for(int i = 0; i < _v; i++){
      std::cout << &_adjList[i] << std::endl;
    }
  }

  void Graph::orderBridges(int *_ptrBridges){
    printf("%d\n", *_ptrBridges);
    for(int i = 0; i < _bridgePairs.size()-1; i+=2){
<<<<<<< HEAD
      std::cout << i << " index " << std::endl;
      std::cout << _bridgePairs[i]-1 << std::endl;
=======
>>>>>>> 1c77a60ae6f4285e408060f00d6282f47bcd1181
      std::cout << _parents[_fromSCC[_bridgePairs[i]-1]]*10 + _parents[_fromSCC[_bridgePairs[i+1]-1]] << " bridge " << std::endl;
    }
    //falta ordernar
    //voltar a separar e dps imprimir
  }
