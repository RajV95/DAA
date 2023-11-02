//BFS BIPARTITE

#include<bits/stdc++.h>
using namespace std;

int size;
bool bfs(vector<vector<int>> &a,int n,vector<int> &visited)
{
    queue<int> Queue;
    vector<int> bfs;
    vector<int>color(a.size(),-1);
    color[n]=0;
    Queue.push(n);
    visited[n]=1;
    while (!Queue.empty())
    {
        int x=Queue.front();
        Queue.pop();
        bfs.push_back(x);
        for(int i=0;i<a[x].size();i++)
        {
            if(visited[i]!=1 && a[x][i]==1)
            {
                color[i]=1-color[x];
                visited[i]=1;
                Queue.push(i);
            }
            else if(a[x][i]=1 && color[i]==color[x])
            {
                return false;
            }
        }   
    }
    return true;
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
    bool Bfs;
    cout <<"Starting vertex :";
    cin >> n;
    Bfs=bfs(a,n,visited);
    if(Bfs)
    {
        cout << "It is bipartitie graph"<<endl;
    }
    else
    {
        cout <<"Not a bipartite graph"<<endl;
    }
    return 0;
}