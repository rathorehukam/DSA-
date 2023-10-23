








#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void deleteGreaterThanpoint(int arr[], int& n, int threshold) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > threshold) {
            count++;
        } else {
            arr[i - count] = arr[i];
        }
    }
    n -= count;
}

void displayHeap(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int n;
    int threshold;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    buildMaxHeap(arr, n);

    cin >> threshold;

    deleteGreaterThanpoint(arr, n, threshold);

    displayHeap(arr, n);

    return 0;
}
