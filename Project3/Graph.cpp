//
// Graph.h
// Cameron Fisher - Section 2
// Last Modified: 12/5/2021
//

#include "Graph.h"
Vertex::Vertex(){
    name = "test";
}
Vertex::Vertex(std::string name) {
this->name = name;
edges.reserve(0);
}

Edge::Edge(std::string name, Vertex *src, Vertex *dest, int weight) {
this->name = name;
this->src = src;
this->dest = dest;
this->weight = weight;
}

Graph::Graph() {
    vertices.reserve(100);
    edges.reserve(100);
}
void Graph::addVertex(Vertex a){
    vertices.push_back(a);

}
void Graph::addEdge(Edge e){
    edges.push_back(e);
    for (int i = 0; i < vertices.size(); i++) { //add to vertex's vector of edges
        if (e.src->name == vertices[i].name) {
            vertices[i].edges.push_back(&edges.back());
            break;
        }
    }
}
void Graph::addEdge(Vertex a, Vertex b, int weight){
    std::ostringstream os; //create edge's name
    os << "e" << edges.size();
    Edge edge(os.str(), &a, &b, weight); //create edge object
    edges.push_back(edge); //add to graph's vector of edges
    for (int i = 0; i < vertices.size(); i++) { //add to vertex's vector of edges
        if (a.name == vertices[i].name) {
            vertices[i].edges.push_back(&edges.back());
            break;
        }
    }
}
void Graph::printShortestPath(Vertex src, Vertex dest){
    if (src.name==dest.name) { //check if same node
        std::cout << src.name << " & " << dest.name << " are the same node!" << std::endl;
        return;
    }
    std::vector<Vertex> nodes = vertices; //used to reference which node is being referred to at certain indexes
    for (int i = 0; i < nodes.size(); i++) { //remove src from nodes
        if (src.name==nodes[i].name) nodes.erase(nodes.begin()+i);
    }
    std::vector<std::string> prev; //save path for printing later
    std::vector<int> distances; //stored distances
    std::stack<std::string> stack; //used for printing
    std::vector<Vertex> Q = nodes; //Q removes nodes as they're visited
    Vertex temp=src;
    int tempInt, min;
    bool visited=true;
    for (int i = 0; i < nodes.size(); i++) { //initialize distances as "infinity" & initialize prev as src name for simplicity's sake
        prev.push_back(src.name);
        distances.push_back(INT_MAX);
    }
    for (int i = 0; i < nodes.size(); i++) { //save initial known distances
        for (int j = 0; j < src.edges.size(); j++) {
            if (nodes[i].name==src.edges[j]->dest->name) {
                distances[i]=src.edges[j]->weight;
            }
        }
    }
    while(!Q.empty()) {
        min=INT_MAX;
        for (int i = 0; i < distances.size(); i++) { //get minimum distance
            visited=true;
            if (distances[i]<min) {
                for (int j = 0; j < Q.size(); j++) {
                    if (Q[j].name==nodes[i].name) {
                        visited = false;
                        break;
                    }
                }
                if (!visited) {
                    min = distances[i];
                    temp = nodes[i];
                    tempInt = i; //store index value
                }
            }
        }
        if(temp.name==dest.name) { //early escape if dest reached
            break;
        }
        for (int i = 0; i < Q.size(); i++) { //remove node from Q
            if (temp.name==Q[i].name) Q.erase(Q.begin()+i);
        }
        for (int i = 0; i < temp.edges.size(); i++) { //save new minimum distances & mark previous node
            for (int j = 0; j < Q.size(); j++) {
                for(int k = 0; k < nodes.size(); k++) {
                if (Q[j].name==temp.edges[i]->dest->name && distances[k]>temp.edges[i]->weight+distances[tempInt]) {
                        if(nodes[k].name==Q[j].name) {
                            prev[k] = temp.name;
                            distances[k] = temp.edges[i]->weight + distances[tempInt];
                            break;
                        }
                    }
                }
            }
        }
    }
    stack.push(dest.name); //push destination node when done into stack
    while (true) { //create path
        if(stack.top()==src.name) break;
        for(int i = 0; i < nodes.size(); i++) {
            if(stack.top()==nodes[i].name)
                stack.push(prev[i]);
        }
    }
    while (!stack.empty()) { //print
        std::cout << stack.top() << " >> ";
        stack.pop();
    }
    std::cout << "\b\b \b\b " << "\nDistance is: " << min << std::endl;
}
void Graph::printAdjList(){
    std::ostringstream os;
    std::cout << "Printing adjList" << std::endl;
    for (int i = 0; i < vertices.size(); i++) { //iterate through vertices
        os << vertices[i].name << " >>"; // start line for vertex
        for (int j = 0; j < edges.size(); j++) { //iterate through edges
            if (edges[j].src->name == vertices[i].name) //if edge's src is vertex, append dest to line
                os << " " << edges[j].dest->name;
        }
        std::cout << os.str() << std::endl; //print adj for vertex
        os.str(""); //reset os
        os.clear();
    }
}
void Graph::breadthFirstSearch(Vertex a){
    std::queue<Vertex*> queue;
    std::vector<std::string> visited;
    visited.reserve(0);
    visited.push_back(a.name);
    queue.push(&a);
    bool visit = false;
    std::cout << "Breadth First Search path starting from: " << a.name << std::endl;
    while (!queue.empty()){
        for(int i = 0; i < edges.size(); i++) {
            if(queue.front()->name==edges[i].src->name) {
                for (int j = 0; j < visited.size(); j++) { //check if already visited
                    if (visited[j] == edges[i].dest->name) {
                        visit = true;
                        break;
                    }
                }
                if (!visit) {
                    queue.push(edges[i].dest);
                    visited.push_back(queue.back()->name);
                } else visit = false;
            }
        }
        std::cout << queue.front()->name << ", ";
        queue.pop();
    }
    std::cout << "\b\b " << std::endl; //get rid of extra ,
}
void Graph::depthFirstSearch(Vertex a){ //pre-order
    std::stack<Vertex*> stack;
    std::vector<std::string> visited;
    visited.reserve(0);
    visited.push_back(a.name);
    stack.push(&a);
    std::string checkVertex = a.name;
    bool visit = false;
    std::cout << "Depth First Search path starting from: " << a.name << std::endl;
    while (!stack.empty()){
        checkVertex = stack.top()->name;
        std::cout << stack.top()->name << ", ";
        stack.pop();
        for(int i = 0; i < edges.size(); i++) {
            if(checkVertex==edges[i].src->name) {
                for (int j = 0; j < visited.size(); j++) { //check if already visited
                    if (visited[j] == edges[i].dest->name) {
                        visit = true;
                        break;
                    }
                }
                if (!visit) {
                    stack.push(edges[i].dest);
                    visited.push_back(stack.top()->name);
                } else visit = false;
            }
        }
    }
    std::cout << "\b\b " << std::endl; //get rid of extra ,
}
void Graph::orderedDepthFirstSearch(Vertex a){ //ordered depending on increasing degree of the destination node.
    std::stack<Vertex*> stack;
    std::vector<std::string> visited;
    visited.reserve(0);
    std::vector<Vertex*> children; //children of top of stack vertex. Does not include visited vertices
    children.reserve(0);
    visited.push_back(a.name);
    stack.push(&a);
    std::string checkVertex = a.name;
    bool visit = false;
    int size = INT_MAX;
    Vertex *vPtr;
    std::cout << "Depth First Search (ordered by increasing degree) path starting from: " << a.name << std::endl;
    while (!stack.empty()){
        size = INT_MAX;
        checkVertex = stack.top()->name;
        std::cout << stack.top()->name << ", ";
        stack.pop();
        for(int i = 0; i < edges.size(); i++) {
            if(checkVertex==edges[i].src->name) {
                for (int j = 0; j < visited.size(); j++) { //check if already visited
                    if (visited[j] == edges[i].dest->name) {
                        visit = true;
                        break;
                    }
                }
                if (!visit) {
                    children.push_back(edges[i].dest);
                    visited.push_back(edges[i].dest->name);
                } else visit = false;
            }
        }
        while (!children.empty()) { //push children in increasing order (by order)
            for (int i = 0; i < children.size(); i++) {
                if (children[i]->edges.size() < size) {
                    vPtr = children[i];
                }
            }
            stack.push(vPtr);
            for (int i = 0; i < children.size(); i++) {
                if (children[i]->name == vPtr->name)
                    children.erase(children.begin()+i); //remove from children vector
            }
        }
    }
    std::cout << "\b\b " << std::endl; //get rid of extra ,
}