#include <stdio.h>
#include <stdlib.h>
#define MAX 100
// Global variables
int dfn[MAX], low[MAX], parent[MAX], time = 0;
int visited[MAX], articulation[MAX];

// Function to perform DFS and find articulation points
void dfnlow(int u, int adj[MAX][MAX], int V) {
    int children = 0, v;
    visited[u] = 1;
    dfn[u] = low[u] = ++time;

    for (v = 0; v < V; v++) {
        if (adj[u][v]) { // Check if there's an edge between u and v
            if (!visited[v]) {
                children++;
                parent[v] = u;
                dfnlow(v, adj, V); // Recursively call DFS for vertex v

                // Update low value of u for parent function calls
                low[u] = (low[u] < low[v]) ? low[u] : low[v];

                // Check if u is an articulation point
                if (parent[u] == -1 && children > 1) { // Root case
                    articulation[u] = 1;
                }
                if (parent[u] != -1 && low[v] >= dfn[u]) { // Non-root case
                    articulation[u] = 1;
                }
            } else if (v != parent[u]) {
                // Update low value if v is already visited and not the parent of u
                low[u] = (low[u] < dfn[v]) ? low[u] : dfn[v];
            }
        }
    }
}

// Function to find all articulation points
void findArticulationPoints(int adj[MAX][MAX], int V) {
    int i;

    // Initialize arrays
    for (i = 0; i < V; i++) {
        parent[i] = -1;
        visited[i] = 0;
        articulation[i] = 0;
    }

    // Perform DFS for all unvisited vertices
    for (i = 0; i < V; i++) {
        if (!visited[i]) {
            dfnlow(i, adj, V);
        }
    }

    // Print articulation points
    printf("Articulation points are:\n");
    for (i = 0; i < V; i++) {
        if (articulation[i]) {
            printf("Router %d\n", i);
        }
    }
}

// Main function
int main() {
    int V, E, i, adj[MAX][MAX] = {0}, u, v;

    // Input number of vertices and edges
    printf("Enter the number of routers (vertices): ");
    scanf("%d", &V);
    printf("Enter the number of connections (edges): ");
    scanf("%d", &E);

    // Input connections (edges)
    printf("Enter the connections (u v):\n");
    for (i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // Undirected graph
    }

    // Find and display articulation points
    findArticulationPoints(adj, V);

    return 0;
}
