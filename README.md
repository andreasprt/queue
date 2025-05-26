# Generic Queue Implementation in C

A flexible and type-safe queue implementation in C that supports generic data types through void pointers and function callbacks.

## Features

- Generic queue implementation that can store any data type
- Configurable maximum queue size
- Custom data copying support through callback functions
- Optional data printing functionality
- Memory-safe operations with proper cleanup
- Thread-unsafe (single-threaded use only)

## API Functions

- `QUEUE_Create`: Creates a new queue with specified configuration
- `QUEUE_Destroy`: Frees all queue resources
- `QUEUE_Enqueue`: Adds an item to the queue
- `QUEUE_Dequeue`: Removes and returns an item from the queue
- `QUEUE_Peek`: Views the front item without removing it
- `QUEUE_IsEmpty`: Checks if queue is empty
- `QUEUE_IsFull`: Checks if queue is at maximum capacity
- `QUEUE_Size`: Returns current number of items in queue
- `QUEUE_Clear`: Removes all items from queue

## Usage Example

```c
// Configure the queue
QueueConfig_t config = {
    .data_size = sizeof(MyData_t),
    .copy_func = MyData_Copy,
    .print_func = MyData_Print  // Optional
};

// Create queue
Queue_t* queue = QUEUE_Create(&config, MAX_QUEUE_SIZE);

// Add data
MyData_t data = {1, "Example", 90.5f};
QUEUE_Enqueue(queue, &data);

// Remove data
MyData_t received;
if (QUEUE_Dequeue(queue, &received)) {
    // Process received data
}

// Clean up
QUEUE_Destroy(queue);

```

## Building

Use the provided Makefile to build the project:

```makefile

make        # Build the project
make clean  # Clean build artifacts

```

## Requirements
- C compiler supporting C11 standard
- Standard C library
- Make build system

## License

MIT License

Copyright (c) 2025 Andreas