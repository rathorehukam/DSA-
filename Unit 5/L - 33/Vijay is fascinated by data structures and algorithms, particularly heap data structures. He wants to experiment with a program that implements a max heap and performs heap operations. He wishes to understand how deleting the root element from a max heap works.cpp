










#include <iostream>
using namespace std;

#define MAX_SIZE 100

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

void deleteRoot(int arr[], int &n)
{
    if (n <= 0)
        return;

    int lastElement = arr[n - 1];
    arr[0] = lastElement;
    n = n - 1;
    heapify(arr, n, 0);
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
}

int main()
{
    int n;
    cin >> n;

    int arr[MAX_SIZE];

    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    buildMaxHeap(arr, n);
    deleteRoot(arr, n);
    printArray(arr, n);

    return 0;
}
