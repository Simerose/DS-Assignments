#include <stdio.h>
#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void insert(int value) {
    if (size == MAX) {
        printf("Priority Queue is full!\n");
        return;
    }

    heap[size] = value;     
    int i = size;
    size++;

    while (i != 0 && heap[(i - 1)/2] < heap[i]) {
        swap(&heap[i], &heap[(i - 1)/2]);
        i = (i - 1) / 2;
    }

    printf("Inserted %d\n", value);
}
int getMax() {
    if (size == 0)
        return -1;
    return heap[0];
}
void maxHeapify(int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size && heap[left] > heap[largest])
        largest = left;

    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        maxHeapify(largest);
    }
}
int extractMax() {
    if (size <= 0)
        return -1;

    int max = heap[0];
    heap[0] = heap[size - 1];  
    size--;

    maxHeapify(0);  
    return max;
}

void display() {
    if (size == 0) {
        printf("Priority Queue is empty!\n");
        return;
    }

    printf("Priority Queue (Heap): ");
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    insert(40);
    insert(20);
    insert(60);
    insert(10);
    insert(80);

    display();

    printf("Max Element = %d\n", getMax());

    printf("Extracted Max = %d\n", extractMax());
    display();

    printf("Extracted Max = %d\n", extractMax());
    display();

    return 0;
}

