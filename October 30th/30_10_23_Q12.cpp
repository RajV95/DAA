// DFS BIPARTITE

#include <bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>> &a, int n, vector<int> &color, int start, int c) {
    color[start] = c;

    for (int i = 0; i < n; i++) {
        if (a[start][i]) {
            if (color[i] == -1) {
                if (!isBipartite(a, n, color, i, 1 - c)) {
                    return false;
                }
            } else if (color[i] == c) {
                return false;
            }
        }
    }
    return true;
}

bool checkBipartite(vector<vector<int>> &a, int n) {
    vector<int> color(n, -1);

    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            if (!isBipartite(a, n, color, i, 0)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    if (checkBipartite(a, n)) {
        cout << "Yes, the graph is bipartite." << endl;
    } else {
        cout << "No, the graph is not bipartite." << endl;
    }

    return 0;
}
