#include <bits/stdc++.h>

using namespace std;

int dp[100][100];

int matrix_chain_multiplication(int arr[], int i, int j)
{
    if(i == j)
    {
        return 0;
    }

    if(dp[i][j]!=0)
    {
        return dp[i][j];
    }

    dp[i][j] = INT_MAX;
    for(int k=i;k<j;k++)
    {
        dp[i][j] = min(matrix_chain_multiplication(arr, i, k) + matrix_chain_multiplication(arr, k+1, j) + arr[i-1]*arr[k]*arr[j], dp[i][j]);
    }

    return dp[i][j];
}

int main()
{
    int input_array[] = {2,3,4,4,1};
    int ans =  matrix_chain_multiplication(input_array, 1, 4);
    cout << ans << endl;

    return 0;
}