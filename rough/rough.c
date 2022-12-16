// Buffer swapping improves performance by overlapping the execution of the producer and the consumer, but only when data is produced and consumed at the same constant rate. In situations where data is produced in bursts of varying lengths or frequencies and the consumer is unable to handle the incoming data at the rate of a burst, multiple buffer slots are useful to hold and process the data at a slower rate of the consumer. Conversely, if the consumer needs to process incoming data in bursts or at a higher granularity, then multiple buffer slots can be used to accumulate the data prior to each burst.

// A circular buffer is a fixed array of buffer slots filled by the producer and emptied by the consumer one slot at a time in ascending order, modulo the buffer size.

// In this assignment, you write c code to simulate a circular buffer.

// 1) Your code will prompt the user to enter the size of the buffer and then create a circular buffer using a linked list (do not use an Array) based on the size provided. The linked list struct must have a data field to represent data produced by the producer. Set this field to -1 to represent an empty buffer. The struct must also have an index field (0 to size-1) to track the position/index of that buffer within the circular buffer. The first index starts at 0 and increments by 1 for each subsequent buffer.

// circular buffer linked list struct

#include <stdio.h>
#include <stdlib.h>

struct circular_buffer
{
    int data;
    int index;
    struct circular_buffer *next;
};

// struct for linked list
struct linked_list
{
    struct circular_buffer *head;
    struct circular_buffer *tail;
};

// function prototypes
void create_circular_buffer(struct linked_list *list, int size);
void print_circular_buffer(struct linked_list *list);
void insert_circular_buffer(struct linked_list *list, int data);
void delete_circular_buffer(struct linked_list *list);
void free_circular_buffer(struct linked_list *list);

int main(void)
{
    struct linked_list list;
    int size;

    // prompt user for size of circular buffer
    printf("Enter the size of the circular buffer: ");
    scanf("%d", &size);

    // create circular buffer
    create_circular_buffer(&list, size);

    // print circular buffer
    print_circular_buffer(&list);

    // insert data into circular buffer