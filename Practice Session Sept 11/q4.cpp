#include<iostream>
using namespace std;
#include<vector>
void binarysearch(vector<vector<int>> a,int i,int s,int e,int target)
{
    int mid=(s+e)/2;
    while(s<=e)
    {
        if(a[i][mid]==target)
        {
            cout<<"element found at index"<<i<<","<<mid<<endl;
            return;
        }
        else if(a[i][mid]>target)
        {
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
        mid=(s+e)/2;
    }
    cout<<"element is not present in the index"<<endl;
}
void binarysearch1(vector<vector<int>> v,int row,int col,int target)
{
    int s=0,e=row-1;
    int mid=(s+e)/2;
    while(s<=e)
    {
        if (target<=v[s][col])
        {
            
        }
        
    }
}
int main()
{
    vector<vector<int>> v{{0,5,6},{6,6,6},{12,18,25}};
    int row=3,col=2;
    int target;
    cout<<"enter the target "<<endl;
    cin>>target;
    int ansr,ansc;
    int i=0,j=0;
    for(int k=0;k<v.size();k++)
    {
        for(int h=0;h<v[k].size();h++)
        {
            cout<<v[k][h]<<" ";
        }cout<<endl;
    }
    binarysearch1(v,row,col,target);
    // while(i<row)
    // {
    //     if(target<=v[i][col] && target>=v[i][0])
    //     {
    //         cout<<"hi"<<i<<endl;
    //         binarysearch(v,i,0,col,target);
    //         break;
    //     }
    //     i=i+1;
    // }
    return 0;
}