    //finding unique ball from 27 balls

#include<bits/stdc++.h>
using namespace std;
int sum(int a[],int x,int y)                          
{
    int sum=0;
    for(int i=x;i<=y;i++)
    {
        sum+=a[i];
    }
    return sum;
}

int main()
{
    int a[]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1},sum1=0,sum2=0;
    sum1=sum(a,0,8);                               
    sum2=sum(a,9,17);
    int x,y;
    if(sum1==sum2) {x=18;y=26;}                   
    else if(sum1>sum2) {x=0;y=8;}
    else {x=9;y=17;}

    sum1=sum(a,x,x+3);
    sum2=sum(a,x+3,x+6);
    if(sum1==sum2) {y=y;x=x+6;} 
    else if(sum1>sum2) {y=x+2;x=x;}
    else {y=x+5;x=x+3;}

    sum1=sum(a,x,x+1);
    sum2=sum(a,x+1,x+2);
    if(sum1==sum2) {x=x+2;}
    else if(sum1>sum2) {x=x;}
    else {x=x+1;}

    cout<<"Position of unique ball is "<<x+1<<endl;


    
}