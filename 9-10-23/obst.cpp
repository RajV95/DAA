#include<bits/stdc++.h>
using namespace std;

int root[100][100];
float obst(vector<float> &keys, vector<float> &values, int i, int j, vector<vector<float>>& dp)
{
    if (i > j)
        return 0.0f;

    if (dp[i][j] != -1.0f)
        return dp[i][j];

    float minCost = INT_MAX;
    float sum = 0.0f;

    for (int k = i; k <= j; k++)
        sum += values[k];

    for (int k = i; k <= j; k++)
    {
        float cost = obst(keys, values, i, k - 1, dp) + obst(keys, values, k + 1, j, dp) + sum;

        if (cost < minCost)
            minCost = cost;
            root[i][j]=k;
    }
    
    return dp[i][j] = minCost;
}

int main()
{
    vector<float> keys = {1, 2, 3, 4};
    vector<float> values = {0.1, 0.2, 0.4, 0.3};
    int n = keys.size();
    vector<vector<float>> dp(n, vector<float>(n, -1.0f));

    float optimalCost = obst(keys, values, 0, n - 1, dp);
    cout << "Optimal Cost: " << optimalCost << endl;
    cout <<"Root :"<<root[0][n-1]  <<endl;

    return 0;
}
