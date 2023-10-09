#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main()
{
    int n;
    cout << "Enter the number of weights: ";
    cin >> n;
    cout << "Enter the constraint weight: " << endl;
    int W;
    cin >> W;

    vector<int> w(n);
    vector<int> p(n);

    cout << "Enter the weights: ";

    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }

    cout << "Enter the profits: ";

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    vector<vector<int>> mat(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (w[i - 1] <= j)
            {
                mat[i][j] = max(mat[i - 1][j], mat[i - 1][j - w[i - 1]] + p[i - 1]);
            }
            else
            {
                mat[i][j] = mat[i - 1][j];
            }
        }
    }

    cout << "Max profit: " << mat[n][W] << endl;

    return 0;
}
