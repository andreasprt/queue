#include "include/queue.h"
#include <stdio.h>
#include <string.h>

#define MAX_QUEUE_SIZE 10
// #define QUEUE_PRINT_FUNC // Uncomment this line to enable print function

typedef struct {
    uint16_t id;
    char nama[20];
    float nilai;
} MyData_t;

void MyData_Copy(void* dest, const void* src) {
    const MyData_t* src_data = (const MyData_t*)src;
    MyData_t* dest_data = (MyData_t*)dest;
    
    dest_data->id = src_data->id;
    strncpy(dest_data->nama, src_data->nama, sizeof(dest_data->nama));
    dest_data->nilai = src_data->nilai;
}

void MyData_Print(const void* data) {
    const MyData_t* d = (const MyData_t*)data;
    printf("ID: %d, Nama: %s, Nilai: %.1f\n", d->id, d->nama, d->nilai);
}

int main() {
    QueueConfig_t config = {
        .data_size = sizeof(MyData_t),
        .copy_func = MyData_Copy,

#if defined(QUEUE_PRINT_FUNC)
        .print_func = MyData_Print
#else
        .print_func = NULL
#endif
    };
    
    Queue_t* myQueue = QUEUE_Create(&config, MAX_QUEUE_SIZE);
    
    if (myQueue == NULL) {
        printf("Failed to create queue!\n");
        return -1;
    }
    
    MyData_t data1 = {1, "Data1", 85.5f};
    MyData_t data2 = {2, "Data2", 92.0f};
    MyData_t data3 = {3, "Data3", 78.3f};
    
    QUEUE_Enqueue(myQueue, &data1);
    QUEUE_Enqueue(myQueue, &data2);
    QUEUE_Enqueue(myQueue, &data3);
    
    printf("Queue size: %d\n", QUEUE_Size(myQueue));
    
    // Get the print function first
    DataPrintFunc print_func = QUEUE_GetPrintFunc(myQueue);
    
    MyData_t temp;
    while (QUEUE_Dequeue(myQueue, &temp)) {
        if (print_func) {
            print_func(&temp);
        } else {
            printf("Dequeued item (no print function)\n");

            printf("ID: %d, Nama: %s, Nilai: %.1f\n", temp.id, temp.nama, temp.nilai);

        }
    }
    
    QUEUE_Destroy(myQueue);
    
    return 0;
}