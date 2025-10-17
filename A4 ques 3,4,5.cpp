//ques 3
#include <stdio.h>

int main() {
    int n, i;

    printf("Enter even number of elements: ");
    scanf("%d", &n);

    int q[n];

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &q[i]);

    printf("Interleaved Queue: ");
    for (i = 0; i < n / 2; i++) {
        printf("%d %d ", q[i], q[i + n / 2]);
    }

    return 0;
}

//ques 4
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int freq[256] = {0};
    char queue[100];
    int front = 0, rear = -1;

    printf("Enter a string: ");
    gets(str);

    printf("Output: ");

    for (int i = 0; i < strlen(str); i++) {
        char ch = str[i];
        freq[ch]++;
        queue[++rear] = ch;

        
        while (front <= rear && freq[queue[front]] > 1)
            front++;

        if (front <= rear)
            printf("%c ", queue[front]);
        else
            printf("-1 ");
    }

    return 0;
}

//ques 5
#include <stdio.h>

#define MAX 100

int q1[MAX], q2[MAX];
int f1 = -1, r1 = -1, f2 = -1, r2 = -1;

void enqueue1(int x) {
    if (f1 == -1) f1 = 0;
    q1[++r1] = x;
}
int dequeue1() {
    return q1[f1++];
}
void enqueue2(int x) {
    if (f2 == -1) f2 = 0;
    q2[++r2] = x;
}
int dequeue2() {
    return q2[f2++];
}

void push(int x) {
    enqueue2(x);
    while (f1 != -1 && f1 <= r1)
        enqueue2(dequeue1());
    
    f1 = f2; r1 = r2; f2 = r2 = -1;
}

void pop() {
    if (f1 == -1 || f1 > r1)
        printf("Stack is empty\n");
    else
        printf("Popped: %d\n", dequeue1());
}

void display() {
    if (f1 == -1 || f1 > r1) {
        printf("Stack empty\n");
        return;
    }
    for (int i = f1; i <= r1; i++)
        printf("%d ", q1[i]);
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    printf("Stack: ");
    display();

    pop();
    printf("After pop: ");
    display();

    return 0;
}
//ques 5(a)
#include <stdio.h>

#define MAX 100

int q[MAX];
int f = -1, r = -1;

void enqueue(int x) {
    if (f == -1) f = 0;
    q[++r] = x;
}

int dequeue() {
    return q[f++];
}

void push(int x) {
    int size = r - f + 1;
    enqueue(x);
    for (int i = 0; i < size; i++)
        enqueue(dequeue());
}

void pop() {
    if (f == -1 || f > r)
        printf("Stack empty\n");
    else
        printf("Popped: %d\n", dequeue());
}

void display() {
    if (f == -1 || f > r) {
        printf("Stack empty\n");
        return;
    }
    for (int i = f; i <= r; i++)
        printf("%d ", q[i]);
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    printf("Stack: ");
    display();

    pop();
    printf("After pop: ");
    display();

    return 0;
}


