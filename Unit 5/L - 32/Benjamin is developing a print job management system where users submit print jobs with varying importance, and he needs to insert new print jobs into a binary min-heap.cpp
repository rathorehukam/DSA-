









#include <iostream>
using namespace std;

struct PrintJob {
    int importance;
};

void swap(struct PrintJob* a, struct PrintJob* b) {
    struct PrintJob temp = *a;
    *a = *b;
    *b = temp;
}

void insertPrintJob(struct PrintJob heap[], int* heapSize, struct PrintJob newPrintJob) {
    (*heapSize)++;

    int i = (*heapSize) - 1;
    heap[i] = newPrintJob;

    while (i > 0 && heap[(i - 1) / 2].importance > heap[i].importance) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void printHeap(struct PrintJob heap[], int heapSize) {
    for (int i = 0; i < heapSize; i++) {
        cout << heap[i].importance << " ";
    }
    cout << endl;
}

int main() {
    struct PrintJob binaryHeap[100];
    int heapSize = 0;

    while (1) {
        struct PrintJob newPrintJob;
        if (!(cin >> newPrintJob.importance)) {
            break;
        }

        insertPrintJob(binaryHeap, &heapSize, newPrintJob);
    }

    printHeap(binaryHeap, heapSize);

    return 0;
}
