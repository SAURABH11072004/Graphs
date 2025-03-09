#include <iostream>
#include <queue>
using namespace std;

class Graph {
    int V;           // Number of vertices
    int **adj;       // Adjacency matrix

public:
    Graph(int V) {
        this->V = V;
        adj = new int*[V]; // Create an array of pointers
        for (int i = 0; i < V; i++) {
            adj[i] = new int[V]{0}; // Initialize matrix with 0
        }
    }

    void addEdge(int u, int v) {
        adj[u][v] = 1;  // Directed graph
        adj[v][u] = 1;  // Remove this line for directed graph
    }

    void BFS(int start) {
        int *visited = new int[V]{0}; // Use 0 and 1 instead of false and true
        queue<int> q;

        visited[start] = 1;
        q.push(start);

        cout << "BFS Traversal: ";
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int i = 0; i < V; i++) {
                if (adj[node][i] == 1 && visited[i] == 0) {
                    visited[i] = 1;
                    q.push(i);
                }
            }
        }
        cout << endl;
        delete[] visited;
    }

    void DFSUtil(int node, int visited[]) {
        visited[node] = 1;
        cout << node << " ";

        for (int i = 0; i < V; i++) {
            if (adj[node][i] == 1 && visited[i] == 0) {
                DFSUtil(i, visited);
            }
        }
    }

    void DFS(int start) {
        int *visited = new int[V]{0}; // Use 0 and 1 instead of false and true
        cout << "DFS Traversal: ";
        DFSUtil(start, visited);
        cout << endl;
        delete[] visited;
    }

    ~Graph() {
        for (int i = 0; i < V; i++) {
            delete[] adj[i];
        }
        delete[] adj;
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    cout << "BFS and DFS Traversals:\n";
    g.BFS(0);
    g.DFS(0);

    return 0;
}
