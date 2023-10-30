// DFS CONNECTEDNESS
// DFS IMPLEMENTATION

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
    int n;
    cout << "Number of vertices"<<endl;
    cin >>n;
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
    int start_vertex;
    cout << "Starting vertex: ";
    cin >> start_vertex;
    dfs(a,start_vertex,visited);
    if(ans.size()!=n)
    {
        cout << "Not connected "<<endl;
    }
    else
    {
        cout <<"Connected"<<endl;
    }
    return 0;
}