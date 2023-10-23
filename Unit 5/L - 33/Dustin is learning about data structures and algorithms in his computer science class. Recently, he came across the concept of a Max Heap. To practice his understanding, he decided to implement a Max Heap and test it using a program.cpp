









#include <iostream>

using namespace std; 

void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

int removeMax(int arr[], int& n) {
    if (n <= 0)
        return -1;

    int maxElement = arr[0];

    arr[0] = arr[n - 1];
    n--;

    maxHeapify(arr, n, 0);

    return maxElement;
}

int main() {
    int* heap = nullptr;
    int n;

    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of elements." << endl;
        return 0;
    }

    heap = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> heap[i];
    }

    if (n > 0) {  
        for (int i = n / 2 - 1; i >= 0; i--) {
            maxHeapify(heap, n, i);
        }

        int maxElement = removeMax(heap, n);

        cout << maxElement << endl;
    }

    for (int i = 0; i < n; i++)
        cout << heap[i] << " ";
    cout << endl;

    delete[] heap;

    return 0;
}
