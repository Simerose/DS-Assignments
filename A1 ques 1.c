#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int arr[MAX];
int n = 0;  

void create() {
int i;
printf("Enter number of elements: ");
scanf("%d", &n);

if (n > MAX)
 {
    printf("Size exceeds maximum limit!\n");
    n = 0;
    return;
}

printf("Enter elements:\n");
for (i = 0; i < n; i++)
{
  scanf("%d", &arr[i]);
}
}

// Function to display array
void display()
 {
    int i;
    if (n == 0) {
        printf("Array is empty!\n");
        return;
    }

    printf("Array elements are: ");
    for (i = 0; i < n; i++) 
	{
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert element
void insert()
 {
    int pos, val, i;
    if (n == MAX) {
    printf("Array is full! Cannot insert.\n");
        return;
    }

    printf("Enter position (1 to %d): ", n+1);
    scanf("%d", &pos);

    if (pos < 1 || pos > n + 1) {
        printf("Invalid position!\n");
        return;
    }

    printf("Enter value to insert: ");
    scanf("%d", &val);

    // Shift elements to right
    for (i = n; i >= pos; i--) {
        arr[i] = arr[i-1];
    }

    arr[pos-1] = val;
    n++;
    printf("Element inserted successfully!\n");
}

// Function to delete element
void delete() {
    int pos, i;
    if (n == 0) {
        printf("Array is empty! Nothing to delete.\n");
        return;
    }

    printf("Enter position to delete (1 to %d): ", n);
    scanf("%d", &pos);

    if (pos < 1 || pos > n) {
        printf("Invalid position!\n");
        return;
    }

    // Shift elements to left
    for (i = pos-1; i < n-1; i++) {
        arr[i] = arr[i+1];
    }

    n--;
    printf("Element deleted successfully!\n");
}

// Function for linear search
void linear_search() {
    int val, i, found = 0;
    if (n == 0) {
        printf("Array is empty!\n");
        return;
    }

    printf("Enter value to search: ");
    scanf("%d", &val);

    for (i = 0; i < n; i++) {
        if (arr[i] == val) {
            printf("Element found at position %d\n", i+1);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Element not found!\n");
}
int main()
{
	int choice;
	while(1){
		printf("1. Create\n");
		printf("2. Display\n");
		printf("3. Insert\n");
		printf("4. Delete\n");
		printf("5. Linear Search\n");
		printf("6. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1: create(); break;
			case 2: display(); break;
			case 3: insert(); break;
			case 4: delete();break;
			case 5: linear_search();break;
			case 6: exit(0);
			default: printf("Invalid choice!");
		}
	}
	return 0;
}
