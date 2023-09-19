#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the value of n:";
    cin>>n;
    int TotalSum=(n*(n-1))/2;
   int arraySum=0;
   int temp;
    cout<<"enter the values in array:";
    for (int i = 0; i < n-1; i++)
    {
        cin>>temp;
        arraySum+=temp;
    }
    
   if (TotalSum-arraySum==0)
      cout<<"0 is the missing number ";
   else
      cout<<TotalSum-arraySum<<" is the missing number ";
   
}