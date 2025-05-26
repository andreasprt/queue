#include "include/queue.h"
#include <string.h>

typedef struct Node {
    void* data;
    struct Node* next;
} Node_t;

struct Queue {
    Node_t* front;
    Node_t* rear;
    uint16_t size;
    uint16_t max_size;
    QueueConfig_t config;
};

Queue_t* QUEUE_Create(const QueueConfig_t* config, uint16_t max_size) {
    Queue_t* q = (Queue_t*)malloc(sizeof(Queue_t));
    if (q == NULL) return NULL;
    
    q->front = q->rear = NULL;
    q->size = 0;
    q->max_size = max_size;
    q->config = *config;
    
    return q;
}

bool QUEUE_IsEmpty(const Queue_t* q) {
    return (q->front == NULL);
}

bool QUEUE_IsFull(const Queue_t* q) {
    return (q->size >= q->max_size);
}

bool QUEUE_Enqueue(Queue_t* q, const void* data) {
    if (QUEUE_IsFull(q)) return false;
    
    Node_t* newNode = (Node_t*)malloc(sizeof(Node_t));
    if (newNode == NULL) return false;
    
    newNode->data = malloc(q->config.data_size);
    if (newNode->data == NULL) {
        free(newNode);
        return false;
    }
    
    // Copy data using provided function or memcpy as fallback
    if (q->config.copy_func) {
        q->config.copy_func(newNode->data, data);
    } else {
        memcpy(newNode->data, data, q->config.data_size);
    }
    
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

bool QUEUE_Dequeue(Queue_t* q, void* data) {
    if (QUEUE_IsEmpty(q)) return false;
    
    Node_t* temp = q->front;
    
    // Copy data to output if pointer is provided
    if (data != NULL) {
        if (q->config.copy_func) {
            q->config.copy_func(data, temp->data);
        } else {
            memcpy(data, temp->data, q->config.data_size);
        }
    }
    
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    free(temp->data);
    free(temp);
    q->size--;
    return true;
}

bool QUEUE_Peek(const Queue_t* q, void* data) {
    if (QUEUE_IsEmpty(q)) return false;
    
    if (q->config.copy_func) {
        q->config.copy_func(data, q->front->data);
    } else {
        memcpy(data, q->front->data, q->config.data_size);
    }
    
    return true;
}

uint16_t QUEUE_Size(const Queue_t* q) {
    return q->size;
}

void QUEUE_Clear(Queue_t* q) {
    while (!QUEUE_IsEmpty(q)) {
        QUEUE_Dequeue(q, NULL);
    }
}

void QUEUE_Destroy(Queue_t* q) {
    QUEUE_Clear(q);
    free(q);
}

DataPrintFunc QUEUE_GetPrintFunc(const Queue_t* q) {
    return q->config.print_func;
}