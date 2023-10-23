









#include <iostream>
using namespace std;
void MaxHeapify(int arr[], int N, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < N && arr[l] > arr[largest])
        largest = l;

    if (r < N && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        MaxHeapify(arr, N, largest);
    }
}
void MaxHeapSort(int arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        MaxHeapify(arr, N, i);

    for (int i = N - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        MaxHeapify(arr, i, 0);
    }
}
void MinHeapify(int arr[], int n, int i)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] < arr[smallest])
        smallest = l;

    if (r < n && arr[r] < arr[smallest])
        smallest = r;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        MinHeapify(arr, n, smallest);
    }
}
void MinHeapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        MinHeapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        MinHeapify(arr, i, 0);
    }
}
void printHeapArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
}

int main()
{
    int n, i;
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int choice;
    cin >> choice;
    if (choice < 1 || choice > 2) {
        cout << "Invalid choice";
        return 0;
    }
    if (choice == 1) {
        MaxHeapSort(arr, n);
    }
    else if (choice == 2) {
        MinHeapSort(arr, n);
    }
    printHeapArray(arr, n);
    return 0;
}
