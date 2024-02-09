#include <stdio.h>
#include <stdlib.h>

struct CircularQueue {
    int *arr;
    int front;
    int rear;
    int size;
};

// Initialize your data structure.
void initCircularQueue(struct CircularQueue *cq, int n) {
    cq->size = n;
    cq->arr = (int *)malloc(sizeof(int) * n);
    cq->front = cq->rear = -1;
}

// Enqueues 'X' into the queue. Returns 1 if it gets pushed into the queue, and 0 otherwise.
int enqueue(struct CircularQueue *cq, int value) {
    if ((cq->front == 0 && cq->rear == cq->size - 1) || (cq->rear == (cq->front - 1) % (cq->size - 1))) {
        // printf("Queue is full\n");
        return 0;
    } else if (cq->front == -1) {
        cq->front = cq->rear = 0;
    } else if (cq->rear == cq->size - 1 && cq->front != 0) {
        cq->rear = 0;
    } else {
        cq->rear++;
    }
    cq->arr[cq->rear] = value;
    return 1;
}

// Dequeues top element from queue. Returns -1 if the queue is empty, otherwise returns the dequeued element.
int dequeue(struct CircularQueue *cq) {
    if (cq->front == -1) {
        return -1;
    }
    int ans = cq->arr[cq->front];
    cq->arr[cq->front] = -1;
    if (cq->rear == cq->front) {
        cq->front = cq->rear = -1;
    } else if (cq->front == cq->size - 1) {
        cq->front = 0;
    } else {
        cq->front++;
    }
    return ans;
}

int main() {
    struct CircularQueue cq;
    initCircularQueue(&cq, 5);

    enqueue(&cq, 1);
    enqueue(&cq, 2);
    enqueue(&cq, 3);
    enqueue(&cq, 4);
    dequeue(&cq);

    free(cq.arr); // Don't forget to free the allocated memory
    return 0;
}
