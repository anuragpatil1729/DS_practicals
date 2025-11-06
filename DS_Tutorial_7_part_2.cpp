#include <iostream>
using namespace std;

#define MAX 100

// DFS function
void dfs(int node, int graph[MAX][MAX], bool visited[], int numNodes) {
    visited[node] = true;
    cout << "Visited: " << node << endl;

    for (int i = 0; i < numNodes; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(i, graph, visited, numNodes);
        }
    }
}

int main() {
    int numNodes, numEdges;
    cout << "Enter number of nodes: ";
    cin >> numNodes;
    cout << "Enter number of edges: ";
    cin >> numEdges;

    int graph[MAX][MAX];

    // Initialize adjacency matrix
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            graph[i][j] = 0;
        }
    }

    cout << "Enter edges (u v) where u and v are nodes (0 to " << numNodes - 1 << "):" << endl;
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1; // For undirected graph
    }

    bool visited[MAX];
    for (int i = 0; i < numNodes; i++) {
        visited[i] = false;
    }

    cout << "\nStarting DFS traversal from node 0:\n";
    dfs(0, graph, visited, numNodes);

    return 0;
}
