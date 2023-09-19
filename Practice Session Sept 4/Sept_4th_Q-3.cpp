#include <iostream>
#include <vector>
using namespace std;
int partition1(int *arr, int low, int high)
{
    int pivot = arr[low];
    int count = 0;
    for (int i = low + 1; i <= high; i++)
    {
        if (arr[i] <= pivot)
            count++;
    }
    int pivotindex = low + count;
    swap(arr[pivotindex], arr[low]);
    int i = low, j = high;
    while (i < pivotindex && j > pivotindex)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] >= pivot)
        {
            j--;
        }
        if (i < pivotindex && j > pivotindex)
            swap(arr[i++], arr[j++]);
    }
    return pivotindex;
}
int partition2(int *arr, int low, int high)
{
    int pivot = arr[high];
    int count = 0;
    for (int i = low; i <= high-1; i++)
    {
        if (arr[i] <= pivot)
            count++;
    }
    int pivotindex = low + count;
    swap(arr[pivotindex], arr[high]);
    int i = low, j = high;
    while (i < pivotindex && j > pivotindex)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] >= pivot)
        {
            j--;
        }
        if (i < pivotindex && j > pivotindex)
            swap(arr[i++], arr[j++]);
    }
    return pivotindex;
}
void quicksort(int *arr, int low, int high)
{
    if (low < high)
    {
        int p1 = partition1(arr, low, high);
        int p2 = partition2(arr, low, high);
        if(p1<=p2)
        {
        quicksort(arr, low, p1 - 1);
        quicksort(arr, p1 + 1, p2-1);
        quicksort(arr, p2 + 1, high);
        }
        else
        {
        quicksort(arr, low, p2 - 1);
        quicksort(arr, p2 + 1, p1-1);
        quicksort(arr, p1 + 1, high);
        }
    }
}
int main()
{
    int arr[9] = {1, 9, 6, 3, 4, 5, 2, 8, 7};
    quicksort(arr, 0, 8);
    for(int i=0;i<9;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
