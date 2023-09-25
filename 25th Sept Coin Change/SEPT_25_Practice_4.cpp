#include<bits/stdc++.h>
using namespace std;
int main() {
    // vector<int>a={1,2,52,0,231,7,1,7};
    // for(int i=0;i<a.size();i++)
    // {
    //     for(int j=i+1;j<a.size();j++)
    //     {
    //         if(a[i]>a[j])
    //         {
    //             int temp=a[i];
    //             a[i]=a[j];
    //             a[j]=temp;
    //         }
    //     }
    // }
    // for(int i=0;i<a.size();i++)
    // {
    //     cout << " " <<a[i];
    // }
    // return 0;
    vector<int>a={1,2,52,0,231,7,1,7};
    for(int i=0;i<a.size();i++)
    {
        for(int j=1;j<a.size()-i;j++)
        {
            if(a[j-1]>a[j])
            {
                int temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
            }
        }
    }
    for(int i=0;i<a.size();i++)
    {
        cout << " " <<a[i];
    }
    return 0;
}