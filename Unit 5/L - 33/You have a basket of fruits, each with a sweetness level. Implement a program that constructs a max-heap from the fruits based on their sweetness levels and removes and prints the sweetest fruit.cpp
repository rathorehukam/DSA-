











#include <iostream>
using namespace std;

struct Fruit {
    int sweetness;
};

void swap(Fruit& x, Fruit& y) {
    Fruit temp = x;
    x = y;
    y = temp;
}

void heapifyDown(Fruit* heap, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left].sweetness > heap[largest].sweetness)
        largest = left;

    if (right < n && heap[right].sweetness > heap[largest].sweetness)
        largest = right;

    if (largest != i) {
        swap(heap[i], heap[largest]);
        heapifyDown(heap, n, largest);
    }
}

Fruit removeSweetestFruit(Fruit* heap, int& n) {
    Fruit sweetestFruit;
    sweetestFruit = heap[0];
    swap(heap[0], heap[n - 1]);
    n--;

    heapifyDown(heap, n, 0);

    return sweetestFruit;
}

int main() {
    Fruit* basket;
    int n;

    cin >> n;
    basket = new Fruit[n];
    for (int i = 0; i < n; i++) {
        cin >> basket[i].sweetness;
    }

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyDown(basket, n, i);
    }

    Fruit eatenFruit = removeSweetestFruit(basket, n);
    cout << eatenFruit.sweetness << endl;
    delete[] basket;
    return 0;
}
