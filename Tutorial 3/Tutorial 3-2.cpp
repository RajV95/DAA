//removing the inversions with time complexity of nlogn
#include <iostream>
using namespace std;
void combine(int arr[],int s, int l, int m)
{
  int i=s,k=s,j=m+1;
  int b[l+1];
  while(i<=m&&j<=l)
  {
    if(arr[i]<=arr[j])
    {
        b[k++]=arr[i++];
    }
    else
    b[k++]=arr[j++];
  }
  while(i<=m)
  {
    b[k++]=arr[i++];
  }
  while(j<=l)
  {
     b[k++]=arr[j++];
  }
  for(int i=s;i<l+1;i++)
  {
    arr[i]=b[i];
  }
}
void merge(int arr[],int s,int l)
{
    if(s<l)
    {
        int mid=(s+l)/2;
        merge(arr,s,mid);
        merge(arr,mid+1,l);
        combine(arr,s,l,mid);
    }
    return;
}
int main()
{
    int n;
    cout<<"enter the size of the array"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cout<<"enter the element  " ;
        cin>>arr[i];
    }
    cout<<"array before removing inversions"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
    merge(arr,0,n);
    cout<<"array after removing inversions"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}