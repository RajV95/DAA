#include <stdio.h>

void printSubset(int set[], int subset[], int n, int subsetSize)
{
    for (int i = 0; i < subsetSize; i++)
    {
        printf("%d ", subset[i]);
    }
    printf("\n");

    int lastElement = (subsetSize == 0) ? 0 : subset[subsetSize - 1];

    for (int i = lastElement; i < n; i++)
    {
        subset[subsetSize] = set[i];
        printSubset(set, subset, n, subsetSize + 1);
    }
}

void generateSubsets(int set[], int n)
{
    int subset[n];
    printSubset(set, subset, n, 0);
}

int main()
{
    int n;
    printf("Enter the size of the set: ");
    scanf("%d", &n);

    int set[n];
    printf("Enter the elements of the set: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &set[i]);
    }

    printf("Subsets of the set:\n");
    generateSubsets(set, n);

    return 0;
}