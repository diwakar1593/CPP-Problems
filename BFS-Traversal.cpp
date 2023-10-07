#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Graph
{
    int V; 
    vector<int> *adj;

public:
    Graph(int V);               
    void addEdge(int v, int w); 
    void BFS(int s);            
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new vector<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); 
}

void Graph::BFS(int s)
{
    
    vector<bool> visited(V, false);
    queue<int> queue;
    visited[s] = true;
    queue.push(s);

    while (!queue.empty())
    {
        s = queue.front();
        cout << s << " ";
        queue.pop();

        
        for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push(*i);
            }
        }
    }
}

int main()
{
    Graph g(6); 
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);

    cout << "BFS traversal starting from vertex 0: ";
    g.BFS(0);

    return 0;
}
