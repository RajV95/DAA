//prims algorithm
#include <iostream>
#include <climits>

using namespace std;

const int INF = INT_MAX;
const int MAX_V = 100; 

int graph[MAX_V][MAX_V];

int primMST(int V) {
    int parent[MAX_V];
    int key[MAX_V];     
    bool inMST[MAX_V];
    for (int i = 0; i < V; i++) {
        key[i] = INF;
        inMST[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = -1;

        for (int v = 0; v < V; v++) {
            if (!inMST[v] && (u == -1 || key[v] < key[u])) {
                u = v;
            }
        }

        inMST[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int totalWeight = 0;
    for (int i = 1; i < V; i++) {
        totalWeight += graph[i][parent[i]];
    }

    return totalWeight;
}

int main() {
    int V, E;
    cin >> V >> E;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < E; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u][v] = weight;
        graph[v][u] = weight;
    }

    int minimumSpanningTreeWeight = primMST(V);
    cout << "Total weight of the minimum spanning tree: " << minimumSpanningTreeWeight << endl;

    return 0;
}