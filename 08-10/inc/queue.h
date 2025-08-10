#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define QUEUE_MAX_SIZE 10
typedef struct Queue {
    int front;                      //队头
    int rear;                       //队尾
    int data[QUEUE_MAX_SIZE];       //数据
} Queue; 

void initQueue(Queue *queue);
Queue* createQueue();
bool isQueueEmpty(Queue *queue);
bool isQueueFull(Queue *queue);
bool enqueue(Queue *queue, int data);
bool dequeue(Queue *queue, int *data);

#endif /* __QUEUE_H__ */