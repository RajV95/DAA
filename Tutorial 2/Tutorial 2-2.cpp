#include<iostream>
using namespace std;

int main()
{
    float a[]={1.1,1,1,1,1,1,1,1,1,1};
    double sum=0;
    for(int i=0;i<10;i++) {sum+=a[i]*i;}
    cout<<"Odd box is "<<(int)(((sum-45.0)*10)+1)<<endl;
}