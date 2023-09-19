//sum of digits

#include <iostream>
using namespace std;
void sumofdigits(int n)
{
    int sum=0;
    while(n)
    {
        sum=sum+n%10;
        n=n/10;
    }
    cout<<sum <<" is the sum";
}
void sumdistinct(int n)
{
    int hash[9]={0};
    int sum=0;
    while(n)
    {
        hash[n%10]++;
        if(hash[n%10]==1)
        {
            sum=sum+n%10;
        }
        n=n/10;
    }
    cout<<sum <<" is the sum";

}
int main()
{
    cout<<"enter the number "<<endl;
    int n;
    cin>>n;
   // sumofdigits(n);
   sumdistinct(n);

    
    return 0;
}