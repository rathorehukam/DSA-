






#include <iostream>
#include <vector>

class MinHeap {
private:
    std::vector<int> heap;
    int size;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void bubbleUp(int i) {
        while (i != 0 && heap[parent(i)] > heap[i]) {
            std::swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

public:
    MinHeap() : size(0) {}

    void insert(int val) {
        if (size == heap.size()) {
            heap.push_back(val);
        } else {
            heap[size] = val;
        }
        bubbleUp(size);
        size++;
    }

    int getSize() const {
        return size;
    }

    void printHeap() {
        for (int i = 0; i < size; i++) {
            std::cout << heap[i];
            if (i < size - 1) {
                std::cout << " ";
            }
        }
    }
};

int main() {
    const int maxHeapSize = 100;
    MinHeap minHeap;
    int val;

    while (std::cin >> val) {
        if (minHeap.getSize() < maxHeapSize) {
            minHeap.insert(val);
        } else {
            std::cerr << "Heap size exceeded" << std::endl;
            return 1;
        }
    }

    minHeap.printHeap();
    return 0;
}
