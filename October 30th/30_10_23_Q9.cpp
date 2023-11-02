//BFS IMPLEMENTATION BRIDGES

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
    vector<int> visited1(n,0);
    vector<int> Bfs;
    cout <<"Starting vertex :";
    cin >> n;
    Bfs=bfs(a,n,visited1);
    for(auto i:Bfs)
    {
        cout << i << " ";
    }
    int y,z;
    cout <<"\nEnter two vertices"<<endl;
    cin >> y;
    cin>>z;

    a[y][z]=0;
    a[z][y]=0;

    vector<int> visited(size,0);
    vector<int> Bfs1;
    cout << "\nStarting vertex"<<endl;
    cin >> n;
    Bfs1=bfs(a,n,visited);
    for(auto i:Bfs1)
    {
        cout << i << " ";
    }

    if (Bfs.size() - Bfs1.size() > 0)
    {
        cout << "\nthe edge is a bridge" << endl;
    }
    else
    {
        cout << "\nthe edge is not a bridge" << endl;
    }
    return 0;
}