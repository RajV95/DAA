#include<stdio.h>

int main(){
    long long int input;
    printf("Enter the value\n");
    scanf("%lld",&input);
    long long int arr[input];
    arr[0]=0;
    arr[1]=1;
    arr[2]=1;
    for(int i=3;i<=input;i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
    printf("%lldth Fibonacci number is %lld\n",input,arr[input-1]);
    for(int j=0;j<input;j++){
        printf("%lld\t",arr[j]);
    }
    return 0;
}