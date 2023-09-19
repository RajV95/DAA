#include <iostream>
#include <vector>

using namespace std;

void maxHeapify(vector<int>& arr, int size, int index) {
    int largest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < size && arr[leftChild] > arr[largest])
        largest = leftChild;

    if (rightChild < size && arr[rightChild] > arr[largest])
        largest = rightChild;

    if (largest != index) {
        swap(arr[index], arr[largest]);
        maxHeapify(arr, size, largest);
    }
}

int main() {
    vector<int> arr = {4, 10, 3, 5, 1, 16, 8};

    int size = arr.size();
    cout << endl;

    for (int i = size / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, size, i);
    }

    int firstmin=min(arr[1],arr[2]);
    int secondmax=max(arr[1],arr[2]);
    if(secondmax==arr[1])
    {
        int x=max(arr[2],arr[3]);
        cout << max(x,firstmin) <<endl;
    }
    else
    {
        int x=max(arr[4],arr[5]);
        cout << max(x,firstmin) <<endl;
    }
    cout << endl;

    return 0;
}
