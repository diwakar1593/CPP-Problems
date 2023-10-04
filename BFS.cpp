#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
public:
    Graph(int vertices);
    void addEdge(int v, int w);
    void BFS(int startVertex);

private:
    int vertices;
    vector<vector<int>> adjacencyList;
};

Graph::Graph(int vertices) {
    this->vertices = vertices;
    adjacencyList.resize(vertices);
}

void Graph::addEdge(int v, int w) {
    adjacencyList[v].push_back(w);
}

void Graph::BFS(int startVertex) {
    // Create a boolean array to keep track of
