#include <iostream>
using namespace std;

#define MAX 100

// BFS traversal without STL
void bfs(int startNode, int graph[MAX][MAX], int numNodes)
{
    bool visited[MAX];
    int queue[MAX];
    int front = 0, rear = 0;

    // Initialize all nodes as unvisited
    for (int i = 0; i < numNodes; i++)
        visited[i] = false;

    // Mark the starting node as visited and enqueue it
    visited[startNode] = true;
    queue[rear++] = startNode;

    while (front < rear)
    {
        int node = queue[front++];
        cout << "Visited: " << node << endl;

        // Check all adjacent nodes
        for (int neighbour = 0; neighbour < numNodes; neighbour++)
        {
            if (graph[node][neighbour] == 1 && !visited[neighbour])
            {
                visited[neighbour] = true;
                queue[rear++] = neighbour;
            }
        }
    }
}

int main()
{
    int numNodes, numEdges;
    cout << "Enter number of nodes: ";
    cin >> numNodes;
    cout << "Enter number of edges: ";
    cin >> numEdges;

    int graph[MAX][MAX] = {0};

    cout << "Enter edges (u v) where u and v are nodes (0 to " << numNodes - 1 << "):" << endl;
    for (int i = 0; i < numEdges; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1; // For undirected graph
    }

    cout << "\nStarting BFS traversal from node 0:\n";
    bfs(0, graph, numNodes);

    return 0;
}