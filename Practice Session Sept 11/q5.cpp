#include <iostream>

using namespace std;

int main()
{
    int A[5] = {1, 2, 3, 4, 4};
    int B[5] = {1, 3, 3, 4, 5};
    int sum1, sum2;
    sum1=sum2=0;
    for(int i=0;i<5;i++)
    {
        sum1 += A[i];
        sum2 += B[i];
    }
    cout << "Sum1, Sum2 : " << sum1 << ", " << sum2 << endl;
    int x, y;
    int diff = sum1-sum2;
    int flag = 0;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(A[i]-B[j] == diff/2)
            {
                flag = 1;
                x=i;
                y=j;
                break;
            }
        }

        if(flag == 1)
        {
            break;
        }
    }


    cout << "The element, index from array A : " << A[x] << ", " << x << endl << "The element, index from array B : " << B[y] << ", " << y << endl;
    return 0;
}