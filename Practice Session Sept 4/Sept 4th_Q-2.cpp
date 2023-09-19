#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int partition(int Arr[],int p, int r){
    int x=Arr[r];
    int i=p-1;
    for(int j=p;j<r;j++){
        if(Arr[j]<=x){
            i=i+1;
            swap(Arr[i],Arr[j]);
        }
    }
    swap(Arr[i+1],Arr[r]);
    return (i+1);
}
void bubble_sort(int Arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<(n-i-1);j++){
            if(Arr[j]>Arr[j+1]){
                swap(Arr[j],Arr[j+1]);
            }
        }
    }
}
void Quick_sort(int Arr[],int p, int r){
    if(p<r){
            int q=partition(Arr,p,r);
            if(r-q+1 <= 30){
            bubble_sort(Arr,r-q+1);
            }
            else{
            Quick_sort(Arr,p,q-1);
            Quick_sort(Arr,q+1,r);
        }
    }
}
int main(){
    int Arr[10]={2,4,6,3,9,0,1,7,8,5};
    srand(time(0));
    const int size = 2000;
    int arr[size];
    for(int i=0;i<size;i++){
        arr[i]=rand();
    }
    Quick_sort(arr,0,1999);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}