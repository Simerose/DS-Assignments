#include <stdio.h>
int main() {
    int a[50], n, i, missing = -1;

    printf("Enter the number of elements:");
    scanf("%d",&n);

    printf("Enter the elements in sorted order:");
    for (i = 0; i<n; i++) {
        scanf("%d",&a[i]);
    }

    for (i = 0; i < n; i++) {
        if (a[i]!= i+1) {
            missing = i+1;
            break;
        }
    }

    if (missing== -1)
        missing= n + 1;  

    printf("The missing number is: %d\n", missing);

    return 0;
}

//ques 3 (b)
#include <stdio.h>

int main() {
    int a[50], n, i;
    int low, high, mid, missing;

    printf("Enter the number of elements (n-1): ");
    scanf("%d", &n);

    printf("Enter the elements in sorted order (from 1 to n with one missing):\n");
    for (i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }

    low = 0;
    high = n-1;
    missing = n+1; 

    while (low<= high) {
        mid = (low+high) / 2;

        if (a[mid]== mid + 1) {
           
            low = mid + 1;
        } else {
            
            missing = mid + 1;
            high = mid - 1;
        }
    }

    printf("The missing number is: %d\n", missing);

    return 0;
}

