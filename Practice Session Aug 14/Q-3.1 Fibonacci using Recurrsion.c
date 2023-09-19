#include <stdio.h>
int fib(int n, int arr[])
{
    if (arr[n] != -1)
    {
        return arr[n];
    }
    else
    {
        arr[n] = fib(n - 1, arr) + fib(n - 2, arr);
    }
    return arr[n];
}
int main()
{
    int input;
    printf("Enter the value\n");
    scanf("%d", &input);
    int arr[input];
    arr[0]=0;
    arr[1]=1;
    arr[2]=1;
    for (int k = 3; k <= input; k++)
    {
        arr[k] = -1;
    }
    int o = fib(input, arr);
    printf("%d\n", o);
    for(int h=0;h<input;h++){
        printf("  %d  ",arr[h]);
    }
    printf("\n");
}