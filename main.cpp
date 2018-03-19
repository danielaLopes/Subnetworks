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
#include "graph.h"

int main(){
  int _time = 0;
  int _count = 0;
  int _numBridges = 0;
  int* _ptrTime = &_time;
  int* _ptrCount = &_count;
  int *_ptrBridges = &_numBridges;
  int numRegions, numConnections, v, u;
  scanf("%d %d", &numRegions, &numConnections);
  Graph *graph = new Graph(numRegions);

  for(int i = 0; i < numConnections; i++){
    scanf("%d %d", &v, &u);
    graph->addVertex(v, u);
  }
<<<<<<< HEAD

  for(int i = 0; i < numRegions; i++) {
    if(graph->getDiscTime(i) == NOTIME) {
      graph->visit(i, _ptrTime, _ptrCount, _ptrBridges);
    }  
  }
=======
  graph->visit(0, _ptrTime, _ptrCount, _ptrBridges);
>>>>>>> 1c77a60ae6f4285e408060f00d6282f47bcd1181
  printf("%d\n", *_ptrCount);
  if(*_ptrCount > 1) {
    graph->orderBridges(_ptrBridges);
  }
  else {
    printf("%d\n", *_ptrBridges);
  }
  delete graph;
  return 0;
}
