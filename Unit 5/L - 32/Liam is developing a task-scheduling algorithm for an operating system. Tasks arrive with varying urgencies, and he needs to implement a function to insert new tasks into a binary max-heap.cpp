







#include <iostream>
using namespace std;

struct Task {
    int urgency;
};

void swap(struct Task* a, struct Task* b) {
    struct Task temp = *a;
    *a = *b;
    *b = temp;
}

void insertTask(struct Task heap[], int* heapSize, struct Task newTask) {
    (*heapSize)++;
    
    int i = (*heapSize) - 1;
    heap[i] = newTask;
    while (i > 0 && heap[(i - 1) / 2].urgency < heap[i].urgency) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void printHeap(struct Task heap[], int heapSize) {
    for (int i = 0; i < heapSize; i++) {
        cout << heap[i].urgency << " ";
    }
    cout << endl;;
}

int main() {
    struct Task taskHeap[100];
    int heapSize = 0;
    
    while (1) {
        struct Task newTask;
        if (!(cin >> newTask.urgency) || newTask.urgency == -1)
            break;
        insertTask(taskHeap, &heapSize, newTask);
    }
    printHeap(taskHeap, heapSize);
    
    return 0;
}
