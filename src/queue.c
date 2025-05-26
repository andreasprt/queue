#include "include/queue.h"
#include <stdlib.h>

Queue_t* QUEUE_Create(uint16_t max_size) {
    Queue_t* q = (Queue_t*)malloc(sizeof(Queue_t));
    if (q != NULL) {
        q->front = q->rear = NULL;
        q->size = 0;
        q->max_size = max_size;
    }
    return q;
}

bool QUEUE_IsEmpty(Queue_t* q) {
    return (q->front == NULL);
}

bool QUEUE_IsFull(Queue_t* q) {
    return (q->size >= q->max_size);
}

bool QUEUE_Enqueue(Queue_t* q, Data_t data) {
    if (QUEUE_IsFull(q)) {
        return false;
    }
    
    Node_t* newNode = (Node_t*)malloc(sizeof(Node_t));
    if (newNode == NULL) {
        return false;
    }
    
    newNode->data = data;
    newNode->next = NULL;
    
    if (QUEUE_IsEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
    return true;
}

bool QUEUE_Dequeue(Queue_t* q, Data_t* data) {
    if (QUEUE_IsEmpty(q)) {
        return false;
    }
    
    Node_t* temp = q->front;
    *data = temp->data;
    q->front = q->front->next;
    
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    free(temp);
    q->size--;
    return true;
}

bool QUEUE_Peek(Queue_t* q, Data_t* data) {
    if (QUEUE_IsEmpty(q)) {
        return false;
    }
    *data = q->front->data;
    return true;
}

uint16_t QUEUE_Size(Queue_t* q) {
    return q->size;
}

void QUEUE_Clear(Queue_t* q) {
    Data_t temp;
    while (!QUEUE_IsEmpty(q)) {
        QUEUE_Dequeue(q, &temp);
    }
}