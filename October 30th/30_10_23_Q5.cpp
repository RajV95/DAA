// DFS IMPLEMENTATION FOR CYCLE

#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
int x=0;
bool dfs(vector<vector<int>> &a,int n,vector<int> &visited,int *x)
{   
    ans.push_back(n);
    visited[n]=1;
    for(int i=0;i<a[n].size();i++)
    {
        
        if(visited[i]!=1 && a[n][i]!=0)
        {
            a[n][i]=0;
            a[i][n]=0;
            bool y=dfs(a,i,visited,x);
        }
        else if(visited[i]==1 && a[n][i]!=0)
        {
            *x=1;
            break;
        }
    }
    if(*x==1)
    {
        return true;
    }
    return false;
    
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
    cout <<"Starting vertex :";
    cin >> n;
    if(dfs(a,n,visited,&x))
    {
        cout<<"graph is cyclic"<<endl;
    }
    else
    {
        cout<<"not cyclic"<<endl;
    }
    for(auto i:ans)
    {
        cout << i << " ";
    }
    return 0;
}