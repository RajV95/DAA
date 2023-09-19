#include<iostream>
using namespace std;
int function(int x){
    return x+2;
}
void init(int arr[],int m){
    for(int i=0;i<m;i++){
        arr[i]=-1;
    }
}
int checkONTO(int domain[],int codomain[],int checkCoDomain[],int size){
    int a;
    for(int i=0;i<size;i++){
        a=function(domain[i]);
        for(int j=0;j<size;j++){
            if(a==codomain[j]){
                checkCoDomain[j]=0;
                break;
            }
        }
    }
    for(int i=0;i<size;i++){
        if(checkCoDomain[i]==-1)
         return 0;
    }
    return 1;
}
int main(){
  int domain[]={-1,2,3,4,5,6};
  int codomain[]={2,3,4,5,6,7};

  int checkCoDomain[6];
 
  init(checkCoDomain,6);
  if(checkONTO(domain,codomain,checkCoDomain,6)){
      cout<<"yes ONTO";
  }else
   cout<<"NOT ONTO";
   