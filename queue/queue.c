#include<stdio.h>
#include<stdlib.h>

struct Queue {
    int rear;
    int capacity;
    int* array;
};

struct Queue* create_new_queue(int capacity) {
    struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
    if(!q) {
        return NULL;
    }
    q->capacity = capacity;
    q->rear = -1;
    q->array = (int*) malloc(capacity * sizeof(int));
    if (!q->array) {
        return NULL;
    }
    return q;
}

int isEmpty(struct Queue* q) {
    return q->rear == -1;
}

int isFull(struct Queue* q) {
    return q->rear == q->capacity-1;
}

void enqueue(struct Queue* q, int data) {
    if (isFull(q)) {
        fprintf(stderr, "queue is full");
        return;
    }
    q->array[q->rear + 1] = data; 
    q->rear++;
}

void dequeue(struct Queue* q) {
    if(isEmpty(q)) {
        fprintf(stderr, "queue is empty, cannot perform dequeue operation");
        return;
    }
    int data = q->array[0];
    printf("Element from dequeue operation: %d\n", data);
    for (int i = 1; i < q->capacity; i++) {
        q->array[i-1] = q->array[i];
    }
    q->rear--;
}

void display(struct Queue* q) {
    for(int i = 0; i <= q->rear; i++) {
        printf("%d ", q->array[i]);
    }
    printf("\n");
}

void free_queue(struct Queue* q) {
    free(q->array);
    free(q);
}

int main() {
    struct Queue* q = create_new_queue(5);
    enqueue(q, 5);
    enqueue(q, 4);
    enqueue(q, 3);
    enqueue(q, 2);
    enqueue(q, 1);
    display(q);
    enqueue(q, 9);
    free_queue(q);
    return 0;
}
