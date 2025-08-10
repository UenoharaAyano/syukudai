#include "../inc/queue.h"
#include "../inc/stack.h"
#include <stdio.h>

int ans = 0;
int main(void)
{
    Queue* q = createQueue();
    for(int i = 0; i<14; i++)
    {
        enqueue(q, i);
    }
    dequeue(q, &ans);
    printf("%d  ",ans);
    dequeue(q, &ans);
    printf("%d  ",ans);


    stack stack;
    stack_init(&stack, 20);
    float value1 = 3.141592;
    int value2 = 666;
    int result1 = 0;
    float result2 = 0;
    stack_push(&stack, &value1, sizeof(float));
    stack_push(&stack, &value2, sizeof(int));
    stack_pull(&stack, &result1, sizeof(int));
    stack_pull(&stack, &result2, sizeof(float));
    printf("%d  ",result1);
    printf("%f  ",result2);
    return 0;
}