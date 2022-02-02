//
// Graph.h
// Cameron Fisher - Section 2
// Last Modified: 12/4/2021
//
#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <sstream>

#ifndef PROJECT3_GRAPH_H
#define PROJECT3_GRAPH_H
class Vertex;
class Edge;
class Vertex {
public:
    std::string name;
    std::vector<Edge*> edges;
    Vertex();
    Vertex(std::string name);
};
class Edge {
public:
    std::string name;
    Vertex *src;
    Vertex *dest;
    int weight;
    Edge(std::string name, Vertex *src, Vertex *dest, int weight);
};

class Graph {
public:
    std::vector<Edge> edges;
    std::vector<Vertex> vertices;
    Graph();
    void addVertex(Vertex a);
    void addEdge(Edge e);
    void addEdge(Vertex a, Vertex b, int weight);
    void printShortestPath(Vertex src, Vertex dest);
    void printAdjList();
    void breadthFirstSearch(Vertex a);
    void depthFirstSearch(Vertex a); //pre-order
    void orderedDepthFirstSearch(Vertex a); //ordered depending on increasing degree of the destination node.
};


#endif //PROJECT3_GRAPH_H
