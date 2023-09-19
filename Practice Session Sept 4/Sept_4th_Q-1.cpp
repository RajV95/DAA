#include<iostream>
#include<vector>
using namespace std;
void binarysearch(vector<int> &arr,int s,int e,int target)
{
    int mid=(s+e)/2;
    while(s<=e)
    {
        if(arr[mid]==target)
        {
        arr.insert(arr.begin()+mid+1,target);
        return;
        }
        else if(mid>0&&arr[mid]>target)
        {
            if(arr[mid-1]<target)
            {
            arr.insert(arr.begin()+mid,target);
            return;
            }
            e=mid-1;
        }
        else
        {
            if(mid<e&&arr[mid+1]>target)
            {
                arr.insert(arr.begin()+mid+1,target);
                return;
            }
            s=mid+1;
        }
        mid=(s+e)/2;
    }
    arr.insert(arr.begin() + e + 1, target);
}
int main()
{
    vector<int> arr={1,5,3,4,6,7,8,156,2};
    for(int i=1;i<arr.size();i++)
    {
        int j=i-1;
        int key=arr[i];
        if(arr[j]<key)
        continue;
        else
        {
            binarysearch(arr,0,j,key);
            arr.erase(arr.begin()+i+1);
        }
        // while(j>=0&&key<arr[j])
        // {
        //     arr[j+1]=arr[j];
        //     j--;
        // }
        //arr[j+1]=key;
    }
    cout<<arr.size()<<endl;
    for(int i=0;i<arr.size();i++)
    cout<<arr[i]<<" ";
}