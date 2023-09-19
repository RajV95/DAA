#include <stdio.h>

int main() {
    int n, flag;
    int arr[100], c = -1;
    scanf("%d", &n);
    for (int i = 2; i < n; i++) {
        flag = 1; 
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }
        if(n%i==0)
        {
            if(flag!=0)
            flag=1;
        }
        else
        {
            flag=0;
        }
        if (flag == 1) {
            arr[++c] = i;
        }
    }
    for (int i = 0; i <= c; i++) {
        printf("%d ", arr[i]);
    }
    int count=0,t=n,ar[100];
    for(int i=0;i<=c;i++)
    {
        count=0;
        while(t%arr[i]==0)
        {
            t/=arr[i];
            count++;
        }
        printf("\n%d->%d",arr[i],count);
    }
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            sum=sum+i;
        printf("\nFactor-> %d",i);
        }
    }
    printf("\nSum is -> %d",sum);
}
