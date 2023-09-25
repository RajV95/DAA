#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
#include <map>
#include <ctime>
#include <bits/stdc++.h>
using namespace std;
int min(int a, int b, int c)
{
    if (a < b && a < c)
    {
        return a;
    }
    else if (b < c && b < a)
        return b;
    return c;
}
int bruteForce(vector<int> &a, int x, map<int, int> &m)
{
    if (x == 0)
    {
        return 0;
    }
    int result = INT_MAX;
    // cout << x << endl;
    if (m.find(x) != m.end())
    {
        return m[x];
    }
    for (int i = 0; i < a.size(); i++)
    {
        if (x >= a[i])
        {
            int c = bruteForce(a, x - a[i], m);
            if (c != INT_MAX && (c + 1) < result)
            {

                result = c + 1;
            }
        }
    }
    m.insert({x, result});
    return result;
}
int main()
{
    int x, y, z, w;
    clock_t start_time;
    time_t start, end;
    vector<int> a;
    cout << "Enter total denominations" << endl;
    cin >> w;
    for (int i = 0; i < w; i++)
    {
        cin >> y;
        a.push_back(y);
    }
    map<int, int> m;
    do
    {
        start_time = clock();
        time(&start);
        cout << "Change :" << endl;
        cin >> x;
        int result = bruteForce(a, x, m);
        cout << "Result : " << result << endl;
        time(&end);
        double time_taken = double(end - start);
        cout << "Time taken by program is : "<< time_taken<< " sec " << endl;
        // cout << "Time Taken :" << clock() - start_time << "ms" << endl;
    } while (x != 0);
    for (auto x : m)
    {
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}
