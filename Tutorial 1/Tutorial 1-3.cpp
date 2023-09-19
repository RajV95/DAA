//minimum and second minimum

#include <iostream>
using namespace std;

int main()
{
    int arr[10]={23,5,456,16,1154,56,46,54,84,100};
    int min=arr[0],smin=arr[1];
    for(int i=1;i<10;i++)
    {
        if(arr[i]<min)
        {
            smin=min;
            min=arr[i];
        }
        else
        {
            if(arr[i]<smin)
            {
                smin=arr[i];
            }
        }
    }
    cout<<"min is "<<min<<" smin is "<<smin;
    return 0;
}