#include <iostream>
#include <cmath>
#include <climits>
#include <vector>

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
int bruteForce(vector<int> &a, int x)
{
    if (x == 0)
    {
        return 0;
    }
    int result = INT_MAX;
    cout << x << endl;
    for (int i = 0; i < a.size(); i++)
    {
        if (x >= a[i])
        {
            int c = bruteForce(a, x - a[i]);
            if (c != INT_MAX && (c + 1) < result)
            {
                result = c + 1;
            }
        }
    }
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
    do
    {
        start_time = clock();
        time(&start);
        cout << "Change :" << endl;
        cin >> x;
        int result = bruteForce(a, x);
        cout << "Result : " << result << endl;
        time(&end);
        double time_taken = double(end - start);
        cout << "Time taken by program is : "<< time_taken<< " sec " << endl;
        // cout << "Time Taken :" << clock() - start_time << "ms" << endl;
    } while (x != 0);
    return 0;
}
