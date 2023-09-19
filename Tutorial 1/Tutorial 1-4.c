//Finding the Square Rooot
#include <stdio.h>
#include <math.h>

void precision(int c, int n)
{
    int p;
    double temp;

    c = (double)c; 
    printf("Enter the precision : ");
    scanf("%d", &p);

    for(double i = c; i * i <= n; i += 0.000001)
    {
        temp = i;
    }

    switch(p)
    {
        case 0: printf("%d", temp);break;
        case 1: printf("%.1f", temp);break;
        case 2: printf("%.2f", temp);break;
        case 3: printf("%.3f", temp);break;
        case 4: printf("%.4f", temp);break;
        case 5: printf("%.5f", temp);break;
        case 6: printf("%.6f", temp);break;

        default:printf("Invalid precision");break;
    }

}

int find(int n)
{
    int s = 1;
    int temp = 0;
    int e = n;
    int mid = (s + e) / 2;
    while (s <= e)
    {
        if (mid * mid == n)
        {
            return mid;
        }

        else if (mid * mid > n)
        {
            e = mid - 1;
        }

        else
        {
            temp = mid;
            s = mid + 1;
        }
        mid = (s + e) / 2;

    }

    return temp;    
}

void main()
{
    int n;
    scanf("%d", &n);

    int c = find(n);
    // printf("%d", c);

    precision(c, n);
    
}