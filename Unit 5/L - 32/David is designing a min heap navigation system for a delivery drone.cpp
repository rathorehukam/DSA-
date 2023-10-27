










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


void insertLocation(Location heap[], int& heapSize, Location newLocation) {
    heap[heapSize] = newLocation;
    int i = heapSize;

    while (i > 0 && heap[(i - 1) / 2].distance > heap[i].distance) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }

    heapSize++;
}

void printHeap(Location heap[], int heapSize) { 
    for (int i = 0; i < heapSize; i++) {
        cout << heap[i].distance << ' ';
    }
    cout << endl;
}

int main() {
    Location minHeap[100]; 
    int heapSize = 0;

    while (true) {
        Location newLocation;
        if (!(cin >> newLocation.distance)) {
            break;
        }

        if (heapSize < 100) { 
            insertLocation(minHeap, heapSize, newLocation);
        } else {
            cout << "Heap is full. Cannot insert more locations." << endl;
        }
    }

    printHeap(minHeap, heapSize);

    return 0;
}
