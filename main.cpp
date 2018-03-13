/*
  --- FIRST ASA'S PROJECT ---
  ---     SUBNETWORKS     ---
  STRONGLY CONNECTED COMPONENTS

  Daniela Lopes, 86403
  Joana Teodoro, 86440

*/


#include <list>
#include <string>
#include <stdio.h>
#include <iostream>
#include "graph.h"

int main(){
  int numRegions, numConnections, v, u;
  scanf("%d %d", &numRegions, &numConnections);
  Graph *graph = new Graph(numRegions);
  for(int i = 0; i < numConnections; i++){
    scanf("%d %d", &v, &u);
    graph->addVertex(v, u);
  }
  //graph->toString();
  graph->visit(0);
  delete graph;
  return 0;
}
