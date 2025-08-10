#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct Stack
{
    char *base;             //栈底
    char *top;              //栈顶
    int size;               //栈的容量
} stack;
void stack_init(stack *stack,int size);
bool stack_IsEmpty(stack *stack);
bool stack_IsFull(stack *stack);
bool stack_push(stack *stack, void* a, unsigned int size);
bool stack_pull(stack *stack, void* a, unsigned int size);
void stack_free(stack *stack);

#endif /*__STACK_H__*/