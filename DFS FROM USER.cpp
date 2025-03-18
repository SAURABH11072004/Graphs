#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    vector<vector<int>> adjMatrix; // Adjacency matrix representation of the graph
    int V; // Number of vertices

public:
    Graph(int vertices) {
        V = vertices;
        adjMatrix.resize(V, vector<int>(V, 0)); // Initialize a VxV matrix with 0
    }

    // Function to add an edge from vertex u to vertex v
    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // Since it's an undirected graph
    }

    // Recursive DFS function to visit vertices
    void DFS(int vertex, vector<bool>& visited) {
        visited[vertex] = true;
        cout << vertex << " ";

        // Visit all adjacent vertices of the current vertex
        for (int i = 0; i < V; ++i) {
            if (adjMatrix[vertex][i] == 1 && !visited[i]) {
                DFS(i, visited);
            }
        }
    }

    // Function to perform DFS traversal starting from vertex start
    void startDFS(int start) {
        vector<bool> visited(V, false);  // Track visited vertices
        cout << "DFS Traversal from vertex " << start << ": ";
        DFS(start, visited);
        cout << endl;
    }
};

int main() {
    int V, E, u, v, start;

    cout << "Enter the number of vertices: ";
    cin >> V;

    Graph g(V);

    cout << "Enter the number of edges: ";
    cin >> E;

    // Input edges from user
    cout << "Enter the edges (u v): \n";
    for (int i = 0; i < E; ++i) {
        cin >> u >> v;
        g.addEdge(u, v);
    }

    cout << "Enter the starting vertex for DFS: ";
    cin >> start;

    // Perform DFS from the starting vertex
    g.startDFS(start);

    return 0;
}
