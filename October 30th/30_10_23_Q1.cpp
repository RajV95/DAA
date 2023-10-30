// BFS IMPLEMENTATION

#include<bits/stdc++.h>
using namespace std;

int size;
vector<int> bfs(vector<vector<int>> &a,int n,vector<int> &visited)
{
    queue<int> Queue;
    vector<int> bfs;
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
                visited[i]=1;
                Queue.push(i);
            }
        }
    }
    return bfs;
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
    vector<int> Bfs;
    cout <<"Starting vertex :";
    cin >> n;
    Bfs=bfs(a,n,visited);
    for(auto i:Bfs)
    {
        cout << i << " ";
    }
    return 0;
}