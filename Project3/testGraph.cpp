//
// Graph.h
// Cameron Fisher - Section 2
// Last Modified: 12/4/2021
//

#include <iostream>
#include "Graph.h"
int main() {
    Graph graph;
    Vertex a("a");
    Vertex b("b");
    Vertex c("c");
    Vertex d("d");
    Vertex f("f");
    graph.addVertex(a);
    graph.addVertex(b);
    graph.addVertex(c);
    graph.addVertex(d);
    graph.addVertex(f);
    graph.addEdge(graph.vertices[0], graph.vertices[1], 8); // a to b
    graph.addEdge(graph.vertices[0], graph.vertices[2], 2); // a to c
    graph.addEdge(graph.vertices[1], graph.vertices[3], 9); // b to d
    graph.addEdge(graph.vertices[3], graph.vertices[0], 5); // d to a
    graph.addEdge(graph.vertices[2], graph.vertices[4], 3); // c to f
    graph.addEdge(graph.vertices[2], graph.vertices[3], 2); // c to d
    graph.addEdge(graph.vertices[4], graph.vertices[0], 7); // f to a
    std::cout << "Done adding! Now testing major functions" << std::endl;
    graph.printAdjList();
    graph.breadthFirstSearch(graph.vertices[0]); //a
    graph.depthFirstSearch(graph.vertices[0]); //a
    graph.orderedDepthFirstSearch(graph.vertices[0]); //a
    graph.printShortestPath(graph.vertices[0], graph.vertices[3]); // a to d
    return 0;
}
