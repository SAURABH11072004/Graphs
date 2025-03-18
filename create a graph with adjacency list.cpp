#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adjList; // Adjacency list for the graph

public:
    Graph(int V) { // Constructor to initialize the graph with V vertices
        this->V = V;
        adjList.resize(V); // Resize the adjacency list to hold V vertices
    }

    // Function to add an edge from vertex u to vertex v
    void addEdge(int u, int v) {
        adjList[u].push_back(v); // Add v to the adjacency list of u
        adjList[v].push_back(u); // Since it's an undirected graph, also add u to the adjacency list of v
    }

    // Function to print the adjacency list representation of the graph
    void printGraph() {
        for (int i = 0; i < V; ++i) {
            cout << "Vertex " << i << ": ";
            for (int v : adjList[i]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Create a graph with 5 vertices
    Graph g(5);

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(3, 4);

    // Print the graph
    g.printGraph();

    return 0;
}
