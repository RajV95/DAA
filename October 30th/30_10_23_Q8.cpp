//DFS ARTICULATION POINT

#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
void dfs(vector<vector<int>> &a,int n,vector<int> &visited)
{

    ans.push_back(n);
    visited[n]=1;
    for(int i=0;i<a[n].size();i++)
    {
        if(visited[i]!=1 && a[n][i]!=0)
        {
            dfs(a,i,visited);
        }
    }
}
int main()
{
    int n,size;
    cout << "Number of vertices"<<endl;
    cin >>n;
    size=n;
    vector<vector<int>> a(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<"enter "<<i<<" row and "<<j<<"th column"<<endl;
            cin>>a[i][j];
        }
    }
    vector<int> visited(n,0);
    vector<int> Dfs;
    cout <<"Starting vertex :";
    cin >> n;
    dfs(a,n,visited);
    for(auto i:ans)
    {
        cout << i << " ";
    }

    cout << "\nenter the vertex" << endl;
    int y;
    cin >> y;
    for (int i = 0; i < size; i++)
    {
        a[y][i] = 0;
        a[i][y] = 0;
    }
    vector<int> visited1(size, 0);
    int size1=ans.size();
    cout << "Starting vertex :";
    cin >> n;
    ans.clear();
    dfs(a, n, visited1);
    int size2=ans.size();

    for(auto i:ans)
    {
        cout << i << " ";
    }
    if (size1-size2 > 1)
    {
        cout << "\nthe vertex is articulated vertex" << endl;
    }
    else
    {
        cout << "\nit is not articulated vertex" << endl;
    }
    return 0;
}