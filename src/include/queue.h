#ifndef QUEUE_H
#define QUEUE_H

#include <stdint.h>
#include <stdbool.h>

// Definisi struct yang akan disimpan dalam queue
typedef struct {
    uint16_t id;
    char nama[20];
    float nilai;
} Data_t;

// Node untuk queue
typedef struct Node {
    Data_t data;
    struct Node* next;
} Node_t;

// Struktur Queue
typedef struct {
    Node_t* front;
    Node_t* rear;
    uint16_t size;
    uint16_t max_size;
} Queue_t;

// Prototipe fungsi
Queue_t* QUEUE_Create(uint16_t max_size);
bool QUEUE_IsEmpty(Queue_t* q);
bool QUEUE_IsFull(Queue_t* q);
bool QUEUE_Enqueue(Queue_t* q, Data_t data);
bool QUEUE_Dequeue(Queue_t* q, Data_t* data);
bool QUEUE_Peek(Queue_t* q, Data_t* data);
uint16_t QUEUE_Size(Queue_t* q);
void QUEUE_Clear(Queue_t* q);

#endif // QUEUE_H