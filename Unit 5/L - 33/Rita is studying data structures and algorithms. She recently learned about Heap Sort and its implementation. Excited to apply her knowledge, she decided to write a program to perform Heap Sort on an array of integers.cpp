










#include <iostream>
using namespace std;

void MaxHeapify(int a[], int i, int n) {
    int largest = i; 
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        MaxHeapify(a, largest, n);
    }
}

void HeapSort(int a[], int n) {
    int i, temp;
    for (i = n - 1; i >= 0; i--) {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        MaxHeapify(a, 0, i);
    }
}

void Build_MaxHeap(int a[], int n) {
    int i;
    for (i = n / 2; i >= 0; i--)
        MaxHeapify(a, i, n);
}

int main() {
    int n, i;
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Build_MaxHeap(arr, n);
    HeapSort(arr, n);

    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
