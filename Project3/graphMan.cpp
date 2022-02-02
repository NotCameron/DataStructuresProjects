//
// Graph.h
// Cameron Fisher - Section 2
// Last Modified: 12/5/2021
// Follow directed prompts to use. Line 33 requires an absolute path to the graph text file
//
#include <iostream>
#include "Graph.h"
#include <fstream>

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
    std::vector<std::string> edges, edge; //for creating edge objects
    std::string input; //for reading streams
    int v1,v2; //save indexes of vertices for creating edge object
    std::ifstream file;
    file.open("C:\\Users\\camer\\CLionProjects\\Project3\\graph.txt"); //absolute path to graph text file
    if(file.is_open()) {
        std::getline(file, input);
        int size = stoi(input); //get number of vertex lines
        //create vertices
        for (int i = 0; i < size; i++) { //create vertices
            std::getline(file, input);
            graph.addVertex(Vertex(input));
        }
        while (file >> input) { //push all edge lines into a vector
            edges.push_back(input);
        }
        std::stringstream ss;
        for (int i = 0; i < edges.size(); i++) { //parse edge lines and create edges
            ss << edges[i];
            for (int j = 0; j < 3; j++) {
                getline(ss, input, ',');
                edge.push_back(input);
            }
            for(int j = 0; j < graph.vertices.size(); j++) {
                if(graph.vertices[j].name==edge[0]) v1=j;
                else if (graph.vertices[j].name==edge[1]) v2=j;
            }
            std::ostringstream os; //create edge's name
            os << "e" << edges.size();
            Edge edgeObj(os.str(), &graph.vertices[v1], &graph.vertices[v2], stoi(edge[2])); //create edge object
            graph.addEdge(edgeObj);
            ss.clear();
            edge.clear();
        }
    } else { //in case file does not open
        std::cout << "File did not open properly!" << std::endl;
        exit(EXIT_FAILURE);
    }
    file.close();
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
                for(int i = 0; i < graph.vertices.size(); i++) { //find index for source vertex
                    if (graph.vertices[i].name==name1) {
                        for (int j = 0; j < graph.vertices.size(); j++) { //find index for destination vertex
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
                for(int i = 0; i < graph.vertices.size(); i++) { //find index for vertex
                    if (graph.vertices[i].name==name1) {
                        graph.breadthFirstSearch(graph.vertices[i]);
                        break;
                    }
                }
                break;
            case 4: //DFS
                std::cout << "Please enter the vertex you want to begin searching from: " << std::endl;
                std::cin >> name1;
                for(int i = 0; i < graph.vertices.size(); i++) { //find index for vertex
                    if (graph.vertices[i].name==name1) {
                        graph.depthFirstSearch(graph.vertices[i]);
                        break;
                    }
                }
                break;
            case 5: //ordered DFS
                std::cout << "Please enter the vertex you want to begin searching from: " << std::endl;
                std::cin >> name1;
                for(int i = 0; i < graph.vertices.size(); i++) { //find index for vertex
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
