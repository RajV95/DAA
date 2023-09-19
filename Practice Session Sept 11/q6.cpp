#include<iostream>
using namespace std;
#include<vector>
void printvector(vector<int> &v)
{
    int n=v.size(),x=0;
    for(int i=0;i<v.size();i++)
    {
        
    }
}
int main()
{
   vector<int> v={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
   cout<<"enter i"<<endl;
   int i;
   cin>>i;
   for(int j=0;j<v.size();j++)
    {
        cout<<v[j]<<" ";
    }cout<<endl;
    int z=0;
   while(v.size()!=1)
   {
    //cout<<"i= "<<i<<" size: "<<v.size()<<endl;
    if(i==v.size()-1)
    {
        v.erase(v.begin());
        i=0;
    }
    else if(i+1==v.size()-1)
    {
        v.erase(v.end()-1);
        i=0;
    }
    else
    {
        v.erase(v.begin()+i+1);
        i=i+1;
    }
    
    printvector(v);
    

   } 
   cout<<v[0]<<" "<<endl;
    return 0;
}