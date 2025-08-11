#include "../inc/queue.h"

void initQueue(Queue *queue) {
    queue->front = 0;
    queue->rear = 0;
    queue->size = QUEUE_MAX_SIZE;
    for(int i = 0; i < QUEUE_MAX_SIZE; i++) {
        queue->data[i] = 0; // 将所有元素初始化为0
    }
}

bool isQueueEmpty(Queue *queue)
{
    if (queue->size == QUEUE_MAX_SIZE)
    {
        return true;
    }else
    {
        return false;
    }
}

bool isQueueFull(Queue *queue)
{

    return ( (queue->size == 0));      // 当 (rear+1) % size == front 时，队满（牺牲一个空间，用空间换时间）
}

bool enqueue(Queue *queue, int data)
{
    if(isQueueFull(queue)) {
        printf ("FULL!Please check the input!\n");
        return false;
    }
    
    queue->data[queue->rear] = data;
    queue->rear = (queue->rear + 1) % QUEUE_MAX_SIZE;
    queue->size --;
    return true;
}

bool dequeue(Queue *queue, int *data)
{
    if(isQueueEmpty(queue)) {
        printf("EMPTY!\n");
        return false;
    }
    queue->size ++;
    *data=queue->data[queue->front];
    queue->front = (queue->front + 1) % QUEUE_MAX_SIZE;
    return true;
}

Queue* createQueue()
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if(queue){
        initQueue(queue);
    }
    return queue;
}