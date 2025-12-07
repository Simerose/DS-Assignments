#include <stdio.h>
void improvedSelectionSort(int a[], int n) {
    int left = 0, right = n - 1;

    while (left < right) {
        int minIndex = left;
        int maxIndex = right;

        
        if (a[minIndex] > a[maxIndex]) {
            int temp = minIndex;
            minIndex = maxIndex;
            maxIndex = temp;
        }

        for (int i = left + 1; i < right; i++) {
            if (a[i] < a[minIndex])
                minIndex = i;
            if (a[i] > a[maxIndex])
                maxIndex = i;
        }

  
        int temp = a[left];
        a[left] = a[minIndex];
        a[minIndex] = temp;

        if (maxIndex == left)
            maxIndex = minIndex;

        temp = a[right];
        a[right] = a[maxIndex];
        a[maxIndex] = temp;

        left++;
        right--;
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    improvedSelectionSort(a, n);

    printf("Sorted array: ");
    printArray(a, n);

    return 0;
}
