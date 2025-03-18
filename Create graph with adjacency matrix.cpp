#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adjMatrix; // Adjacency matrix

public:
    // Constructor to initialize the graph with V vertices
    Graph(int V) {
        this->V = V;
        adjMatrix.resize(V, vector<int>(V, 0)); // Initialize V x V matrix with 0
    }

    // Function to add an edge from vertex u to vertex v
    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1; // Add an edge from u to v
        adjMatrix[v][u] = 1; // Since it's an undirected graph, also add an edge from v to u
    }

    // Function to print the adjacency matrix
    void printGraph() {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                cout << adjMatrix[i][j] << " "; // Print the adjacency matrix
            }
            cout << endl;
        }
    }
};

int main() {
    // Create a graph with 5 vertices
    Graph g(5);

    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(3, 4);

    // Print the graph's adjacency matrix
    g.printGraph();

    return 0;
}
