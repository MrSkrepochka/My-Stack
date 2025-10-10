#include "Errors.h"

const int CapacityDoubler = 2;


void StackInit (Stack_t* stk, size_t capacity)
{
    *stk = {NULL, 0, 0};
    stk -> size = 0;
    stk -> capacity = capacity;
    stk -> data = (int*) calloc (capacity, sizeof(int));
    return;
}

void StackPush (Stack_t* stk, int value)
{

    if (stk -> size < stk -> capacity)
    {
        stk -> data [stk -> size] = value;
        stk -> size++;
    } else
    {
        stk -> capacity *= CapacityDoubler;
        stk -> data = (int*) realloc (stk -> data, stk -> capacity * sizeof(int));

        assert (stk != NULL);
        assert (stk -> data);
        stk -> data [stk -> size] = value;
        stk -> size++;
    }

    return;
}

int StackPop (Stack_t* stk)
{
    int x = stk -> data [stk -> size - 1];
    stk -> data [stk -> size -1] = 0;
    stk -> size--;
    return x;
}

void StackDestroy (Stack_t* stk)
{

    free(stk -> data);
    stk -> data = NULL;
    stk -> size = 0;
    stk -> capacity = 0;
    stk = NULL;
    return;

}

void StackAdd (Stack_t* stk)
{
    int x1 = StackPop (stk);
    int x2 = StackPop (stk);
    StackPush(stk, x1 + x2);
    return;
}

void StackDiv (Stack_t* stk)
{
    int divide_by = StackPop(stk);
    int to_divide = StackPop(stk);
    int result = to_divide / divide_by;
    StackPush(stk, result);
    return;
}

void StackMul (Stack_t* stk)
{
    int x1 = StackPop (stk);
    int x2 = StackPop (stk);
    StackPush(stk, x1 * x2);
    return;
}
