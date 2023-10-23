







#include <iostream>
using namespace std;

struct Bid {
    int bid_amount;
};

void swap(Bid& a, Bid& b) {
    Bid temp = a;
    a = b;
    b = temp;
}

void insertBid(Bid heap[], int& heapSize, Bid newBid) {
    heap[heapSize] = newBid;
    int i = heapSize;

    while (i > 0 && heap[(i - 1) / 2].bid_amount < heap[i].bid_amount) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }

    heapSize++;
}

void printHeap(Bid heap[], int heapSize) {
    for (int i = 0; i < heapSize; i++) {
        cout << heap[i].bid_amount << ' ';
    }
    cout << endl;
}

int main() {
    int maxSize = 100;  
    Bid binaryHeap[maxSize];
    int heapSize = 0;

    while (true) {
        Bid newBid;
        if (!(cin >> newBid.bid_amount)) {
            break;
        }

        if (heapSize < maxSize) {
            insertBid(binaryHeap, heapSize, newBid);
        } else {
            cout << "Heap is full. Cannot insert more bids." << endl;
        }
    }

    printHeap(binaryHeap, heapSize);

    return 0;
}
