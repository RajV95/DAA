#include<iostream>
#include<vector>
using namespace std;
void subset(int arr[],vector<int> &v,vector<vector<int>> &ans,int size,int index)
{
    if(index>=size)
    { 
          ans.push_back(v);
        return;
    }
    v.push_back(arr[index]);
    subset(arr,v,ans,4,index+1);
    v.pop_back();
    subset(arr,v,ans,4,index+1);

}
int main()
{
    int arr[4]={1,2,3,4};
    vector<int> v;
    vector<vector<int>> ans;
    int index=0;
    subset(arr,v,ans,4,index);
    for(int i=0;i<ans.size();i++)
    {
        cout<<"{";
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<"("<<ans[i][j]<<" "<<ans[i][j]<<"),";
        }cout<<"}"<<endl;
    }
}