



#include <iostream>
using namespace std;

struct Location {
    int distance;
};

void swap(Location& a, Location& b) {
    Location temp = a;
    a = b;
    b = temp;
}

void insertLocation(Location* heap, int& heapSize, Location newLocation) {
    heapSize++;

    int i = heapSize - 1;
    heap[i] = newLocation;

    while (i > 0 && heap[i].distance < heap[(i - 1) / 2].distance) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void printHeap(const Location* heap, int heapSize) {
    for (int i = 0; i < heapSize; i++) {
        cout << heap[i].distance << " ";
    }
    cout << endl;
}

int main() {
    const int maxHeapSize = 100;
    Location* binaryHeap = new Location[maxHeapSize];
    int heapSize = 0;

    while (true) {
        Location newLocation;
        if (!(cin >> newLocation.distance)) {
            break;
        }

        insertLocation(binaryHeap, heapSize, newLocation);
    }

    printHeap(binaryHeap, heapSize);

    delete[] binaryHeap;

    return 0;
}
