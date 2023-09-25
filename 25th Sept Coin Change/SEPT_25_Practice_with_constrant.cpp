#include <iostream>
#include <cmath>
#include<climits>
#include<vector>
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
int res=0;
int bruteForce(vector<int> &a, int x,vector <int > &b)
{
    for(int i=0;i<a.size();i++)
    {
        res=res+a[i]*b[i];
    }
    if(x>res)
    {
        return 0;
    }
    if (x==0)
    {
        return 0;
    }
    int result=INT_MAX;
    //cout << x << endl;
    for(int i=0;i<a.size();i++)
    {
        if(x>=a[i] && b[i]!=0)
        {
            b[i]--;
            int c=bruteForce(a,x-a[i],b);
            if(c!=INT_MAX && (c+1)<result)
            {
            result=c+1; 
            }
        }
    }
    return result;
}
int main()
{
    int x,y,z,w,c,d,e;
    cout << "Change :" << endl;
    cin >> x;
    vector<int> a;
    cout << "Enter total denominations" << endl;
    cin >> w;
    for (int i = 0; i < w; i++)
    {
        cin >> y;
        a.push_back(y);
    }
    cout << "Capacity "<<endl;
    vector <int> b;
    for (int i = 0; i < w; i++)
    {   cin >> z;
        b.push_back(z);
    }
    int result = bruteForce(a, x,b);
    cout << "Result : " << result << endl;
    return 0;
}
