










#include <iostream>
#include <vector>

using namespace std;

void maxHeapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

int extractMax(vector<int>& arr) {
    int n = arr.size();
    if (n <= 0) {
        return -1;
    }

    int maxElement = arr[0];
    swap(arr[0], arr[n - 1]);
    arr.pop_back();
    maxHeapify(arr, n - 1, 0);

    return maxElement;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    buildMaxHeap(arr);
    int maxElement = extractMax(arr);

    cout << maxElement << endl;
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i != arr.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
