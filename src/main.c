#include "include/queue.h"
#include <stdio.h>

#define MAX_QUEUE_SIZE 2


#if 1
int main() {
    // Inisialisasi queue
    Queue_t* myQueue = QUEUE_Create(MAX_QUEUE_SIZE);
    
    if (myQueue == NULL) {
        printf("Gagal membuat queue!\n");
        return -1;
    }
    
    // Contoh data
    Data_t data1 = {1, "Data1", 85.5f};
    Data_t data2 = {2, "Data2", 92.0f};
    Data_t data3 = {3, "Data3", 78.3f};
    
    // Enqueue data
    if (!QUEUE_Enqueue(myQueue, data1)) {
        printf("Gagal enqueue data1!\n");
    }
    if (!QUEUE_Enqueue(myQueue, data2)) {
        printf("Gagal enqueue data2!\n");
    }
    if (!QUEUE_Enqueue(myQueue, data3)) {
        printf("Gagal enqueue data3!\n");
    }
    
    // Tampilkan ukuran queue
    printf("Ukuran queue: %d\n", QUEUE_Size(myQueue));
    
    // Dequeue dan tampilkan data
    Data_t temp;
    while (QUEUE_Dequeue(myQueue, &temp)) {
        printf("Dequeue: ID=%d, Nama=%s, Nilai=%.1f\n", 
               temp.id, temp.nama, temp.nilai);
    }

    //Tampilkan ukuran queue
    printf("Ukuran queue setelah cetak sebelumnya: %d\n", QUEUE_Size(myQueue));

    if (!QUEUE_Enqueue(myQueue, data3)) {
        printf("Gagal enqueue data3!\n");
    }

    while (QUEUE_Dequeue(myQueue, &temp)) {
        printf("Dequeue: ID=%d, Nama=%s, Nilai=%.1f\n", 
               temp.id, temp.nama, temp.nilai);
    }
    
    // Bersihkan queue
    QUEUE_Clear(myQueue);
    
    return 0;
}
#endif