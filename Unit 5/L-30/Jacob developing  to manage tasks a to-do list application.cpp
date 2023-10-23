









#include <iostream>
using namespace std;

struct Task {
    int priority;
};

void swap(Task& a, Task& b) {
    Task temp = a;
    a = b;
    b = temp;
}


void insertTaskPriority(Task heap[], int& heapSize, Task newTask) {
    heapSize++;

    int i = heapSize - 1;
    heap[i] = newTask;

    while (i > 0 && heap[(i - 1) / 2].priority > heap[i].priority) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void printHeap(Task heap[], int heapSize) {
    for (int i = 0; i < heapSize; i++) {
        cout << heap[i].priority << " ";
    }
    cout << endl;
}

int main() {
    Task minHeap[100];  
    int heapSize = 0;

    while (true) {
        Task newTask;
        if (!(cin >> newTask.priority)) {
            break;
        }

        insertTaskPriority(minHeap, heapSize, newTask);
    }
    printHeap(minHeap, heapSize);

    return 0;
}
