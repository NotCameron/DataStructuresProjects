//
// Graph.h
// Cameron Fisher - Section 2
// Last Modified: 12/5/2021
//

#include <iostream>
#include "Graph.h"
int menu() {
    int selection;
    std::cout << "  GraphMan" << std::endl <<
              "  ----------------------------------------------" << std::endl <<
              "Please select one of the following:" << std::endl <<
              " [1] Print the shortest path between two nodes" << std::endl <<
              " [2] Print adjacency list" << std::endl <<
              " [3] Breath First Search" << std::endl <<
              " [4] Depth First Search" << std::endl <<
              " [5] Ordered Depth First Search" << std::endl <<
              " [6] Exit Program" << std::endl <<
              "Enter your selection: ";
    std::cin >> selection;
    return selection;
}

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
    graph.addEdge(a, b, 8);
    graph.addEdge(a, c, 2);
    graph.addEdge(b, d, 9);
    graph.addEdge(d, a, 5);
    graph.addEdge(c, f, 3);
    graph.addEdge(c, d, 2);
    graph.addEdge(f, a, 7);
    int option;
    std::string name1, name2;

    //Main loop
    while (true) {
        option = menu(); //call menu and await option
        switch (option) {
            case 1: //print shortest path between two nodes
                std::cout << "Please enter the source vertex you want to begin searching from: " << std::endl;
                std::cin >> name1;
                std::cout << "Please enter the destination vertex you want to begin searching from: " << std::endl;
                std::cin >> name2;
                for(int i = 0; i < graph.vertices.size(); i++) {
                    if (graph.vertices[i].name==name1) {
                        for (int j = 0; j < graph.vertices.size(); j++) {
                            if (graph.vertices[j].name == name2) {
                                graph.printShortestPath(graph.vertices[i], graph.vertices[j]);
                                break;
                            }
                        }
                    }
                }
                break;
            case 2: //print adjacency list
                graph.printAdjList();
                break;
            case 3: //BFS
                std::cout << "Please enter the vertex you want to begin searching from: " << std::endl;
                std::cin >> name1;
                for(int i = 0; i < graph.vertices.size(); i++) {
                    if (graph.vertices[i].name==name1) {
                        graph.breadthFirstSearch(graph.vertices[i]);
                        break;
                    }
                }
                break;
            case 4: //DFS
                std::cout << "Please enter the vertex you want to begin searching from: " << std::endl;
                std::cin >> name1;
                for(int i = 0; i < graph.vertices.size(); i++) {
                    if (graph.vertices[i].name==name1) {
                        graph.depthFirstSearch(graph.vertices[i]);
                        break;
                    }
                }
                break;
            case 5: //ordered DFS
                std::cout << "Please enter the vertex you want to begin searching from: " << std::endl;
                std::cin >> name1;
                for(int i = 0; i < graph.vertices.size(); i++) {
                    if (graph.vertices[i].name==name1) {
                        graph.orderedDepthFirstSearch(graph.vertices[i]);
                        break;
                    }
                }
                break;
            case 6: //exit program
                return 0;
            default: //if invalid option selected
                std::cout << "Invalid option! Please try again!" << std::endl << std::endl;
        }
    }
}