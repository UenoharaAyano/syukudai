#include "../inc/stack.h"

void stack_init(stack *stack,int size)
{
    stack->base = (char *)malloc(size * sizeof(char));
    stack->top = stack->base;
    stack->size = size;
}

bool stack_IsEmpty(stack *stack)
{
    return(stack->base == stack->top);
}

bool stack_IsFull(stack *stack)
{
    return((stack->base - stack->top)>=stack->size);
}

bool stack_push(stack *stack, void* a, unsigned int size)
{
    if(stack_IsFull(stack))
        return false;
    stack->top -= size;
    memcpy (stack->top, a, size);
    return true;
}

bool stack_pull(stack *stack, void* a, unsigned int size)
{
    if(stack->base - stack->top < size)
        return false;
    memcpy(a, stack->top, size);
    stack->top += size;
    return true;
}

void stack_free(stack *stack)
{
    free(stack->base);
    stack->base = NULL;
    stack->top = NULL;
}