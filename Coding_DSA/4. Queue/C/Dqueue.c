#include <stdio.h>
#include <stdlib.h>

struct Deque {
    int *arr;
    int front;
    int rear;
    int size;
};

// Initialize your data structure.
void initDeque(struct Deque *deque, int n) {
    deque->size = n;
    deque->arr = (int *)malloc(sizeof(int) * n);
    deque->front = deque->rear = -1;
}

// Pushes 'X' in the front of the deque. Returns 1 if it gets pushed into the deque, and 0 otherwise.
int pushFront(struct Deque *deque, int x) {
    if (isEmpty(deque)) {
        deque->front = deque->rear = 0;
    } else if (isFull(deque)) {
        return 0;
    } else if (deque->front == 0 && deque->rear != deque->size - 1) {
        deque->front = deque->size - 1;
    } else {
        deque->front--;
    }

    deque->arr[deque->front] = x;
    return 1;
}

// Pushes 'X' in the back of the deque. Returns 1 if it gets pushed into the deque, and 0 otherwise.
int pushRear(struct Deque *deque, int x) {
    if (isEmpty(deque)) {
        deque->front = deque->rear = 0;
    } else if (isFull(deque)) {
        return 0;
    } else if (deque->front != 0 && deque->rear == deque->size - 1) {
        deque->rear = 0;
    } else {
        deque->rear++;
    }

    deque->arr[deque->rear] = x;
    return 1;
}

// Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
int popFront(struct Deque *deque) {
    if (isEmpty(deque)) {
        return -1;
    }

    int ans = deque->arr[deque->front];
    deque->arr[deque->front] = -1;

    if (deque->front == deque->rear) {
        deque->front = deque->rear = -1;
    } else if (deque->front == deque->size - 1) {
        deque->front = 0;
    } else {
        deque->front++;
    }

    return ans;
}

// Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
int popRear(struct Deque *deque) {
    if (isEmpty(deque)) {
        return -1;
    }

    int ans = deque->arr[deque->rear];
    deque->arr[deque->rear] = -1;

    if (deque->front == deque->rear) {
        deque->front = deque->rear = -1;
    } else if (deque->rear == 0) {
        deque->rear = deque->size - 1;
    } else {
        deque->rear--;
    }

    return ans;
}

// Returns the first element of the deque. If the deque is empty, it returns -1.
int getFront(struct Deque *deque) {
    if (isEmpty(deque)) {
        return -1;
    } else {
        return deque->arr[deque->front];
    }
}

// Returns the last element of the deque. If the deque is empty, it returns -1.
int getRear(struct Deque *deque) {
    if (isEmpty(deque)) {
        return -1;
    } else {
        return deque->arr[deque->rear];
    }
}

// Returns 1 if the deque is empty. Otherwise returns 0.
int isEmpty(struct Deque *deque) {
    return deque->front == -1;
}

// Returns 1 if the deque is full. Otherwise returns 0.
int isFull(struct Deque *deque) {
    return (deque->front == 0 && deque->rear == deque->size - 1) || (deque->front != 0 && deque->rear == (deque->front - 1) % (deque->size - 1));
}

int main() {
    struct Deque deque;
    initDeque(&deque, 10);

    // Your main code goes here

    free(deque.arr); // Don't forget to free the allocated memory
    return 0;
}
