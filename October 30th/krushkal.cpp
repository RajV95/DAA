//kruskal algorithm
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_V = 100; 

struct Edge {
    int u, v, weight;
};

Edge edges[MAX_V * MAX_V];

int parent[MAX_V];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unionSets(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        parent[y] = x;
    }
}

int kruskalMST(Edge edges[], int E) {
    sort(edges, edges + E, [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    int mstWeight = 0;
    for (int i = 0; i < E; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        if (find(u) != find(v)) {
            mstWeight += weight;
            unionSets(u, v);
        }
    }

    return mstWeight;
}

int main() {
    int V, E;
    cin >> V >> E;

    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    int minimumSpanningTreeWeight = kruskalMST(edges, E);
    cout << "Total weight of the minimum spanning tree: " << minimumSpanningTreeWeight << endl;

    return 0;
}