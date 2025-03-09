#include <iostream>
using namespace std;

// Node structure for adjacency list
struct Node {
    int vertex;
    Node* next;
};

// Graph class using adjacency list
class Graph {
    int V;
    Node** adj; // Array of linked lists

public:
    Graph(int a) {
        V = a;
        adj = new Node*[V];  // Step 1: Create an array of pointers

        for (int i = 0; i < V; i++) {
            adj[i] = nullptr;  // Initialize each list as empty
        }
    }

    // Function to add an edge (undirected)
    void addEdge(int u, int v) {
        Node* newNode1 = new Node{v, adj[u]};
        adj[u] = newNode1;

        Node* newNode2 = new Node{u, adj[v]};
        adj[v] = newNode2;
    }

    // Function to display the adjacency list
    void display() {
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << " -> ";
            Node* temp = adj[i];
            while (temp != nullptr) {  // Explicitly checking for nullptr
                cout << temp->vertex << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    // Destructor to free memory
    ~Graph() {
        for (int i = 0; i < V; i++) {
            Node* temp = adj[i];
            while (temp != nullptr) {  // Explicitly checking for nullptr
                Node* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
        }
        delete[] adj;
    }
};

int main() {
    Graph g(3);  // Creates a graph with 3 vertices
    g.addEdge(0, 1);
    g.addEdge(1, 2);

    cout << "Adjacency List:\n";
    g.display();

    return 0;
}
