#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> include, exclude;

void dfs(int u, int p) {
    include[u] = 1;
    exclude[u] = 0;

    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
            include[u] += exclude[v];
            exclude[u] += max(include[v], exclude[v]);
        }
    }
}

int maximumIndependentSet(int root) {
    dfs(root, -1);
    return max(include[root], exclude[root]);
}

int main() {
    int n;
    cin >> n;

    adj.resize(n);
    include.resize(n);
    exclude.resize(n);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int root = 0;
    int maxSetSize = maximumIndependentSet(root);

    cout << "Maximum Independent Set Size: " << maxSetSize << endl;

    return 0;
}
