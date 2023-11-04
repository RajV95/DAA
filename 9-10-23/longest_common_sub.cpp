#include <bits/stdc++.h>
using namespace std;

int dp[101][101];

int longest_common_subsequence(string s1, string s2, int n1, int n2)
{
    if (n1 == 0 || n2 == 0)
    {
        return 0;
    }

    if (dp[n1][n2] != 0)
    {
        return dp[n1][n2];
    }

    if (s1[n1 - 1] == s2[n2 - 1])
    {
        dp[n1][n2] = 1 + longest_common_subsequence(s1, s2, n1 - 1, n2 - 1);
    }
    else
    {
        dp[n1][n2] = max(longest_common_subsequence(s1, s2, n1 - 1, n2), longest_common_subsequence(s1, s2, n1, n2 - 1));
    }

    return dp[n1][n2];
}

int main()
{
    string s1, s2;
    cin >> s1;
    cin >> s2;
    int n1 = s1.length();
    int n2 = s2.length();

    int lcsLength = longest_common_subsequence(s1, s2, n1, n2);
    cout << lcsLength << endl;

    for (int i = 0; i <= n1; i++)
    {
        for (int j = 0; j <= n2; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
