#ifndef QUEUE_H
#define QUEUE_H

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

// Forward declaration
typedef struct Queue Queue_t;

// Function pointer type for data copying
typedef void (*DataCopyFunc)(void* dest, const void* src);

// Function pointer type for data printing
typedef void (*DataPrintFunc)(const void* data);

// Queue configuration structure
typedef struct {
    size_t data_size;       // Size of the data structure
    DataCopyFunc copy_func; // Function to copy data
    DataPrintFunc print_func; // Function to print data (optional)
} QueueConfig_t;

// Queue API
Queue_t* QUEUE_Create(const QueueConfig_t* config, uint16_t max_size);
bool QUEUE_IsEmpty(const Queue_t* q);
bool QUEUE_IsFull(const Queue_t* q);
bool QUEUE_Enqueue(Queue_t* q, const void* data);
bool QUEUE_Dequeue(Queue_t* q, void* data);
bool QUEUE_Peek(const Queue_t* q, void* data);
uint16_t QUEUE_Size(const Queue_t* q);
void QUEUE_Clear(Queue_t* q);
void QUEUE_Destroy(Queue_t* q);

DataPrintFunc QUEUE_GetPrintFunc(const Queue_t* q);

#endif // QUEUE_H