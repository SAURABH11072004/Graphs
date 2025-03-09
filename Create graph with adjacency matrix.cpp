#include <iostream>
using namespace std;

class Graph {
    int V;
    int **adj;  // Pointer to a 2D adjacency matrix

public:
    Graph(int a) {
       V = a;
        adj = new int*[V];  // Step 1: Create an array of pointers

        for (int i = 0; i < V; i++) {
            adj[i] = new int[V]{0};  // Step 2: Allocate and initialize each row
        }
    }

    void addEdge(int u, int v) {
        adj[u][v] = 1;
        adj[v][u]=1;// Set adjacency matrix value to 1 (directed edge)
    }

    void display() {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }

    ~Graph() {  // Destructor to free allocated memory
        for (int i = 0; i < V; i++) {
            delete[] adj[i];  // Delete each row
        }
        delete[] adj;  // Delete row pointers
    }
};

int main() {
    Graph g(3);  // Creates a graph with 3 vertices
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    
    cout << "Adjacency Matrix:\n";
    g.display();
    
    return 0;
}
