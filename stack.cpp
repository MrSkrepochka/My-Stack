#include "Errors.h"

const int CapacityDoubler = 2;

Err_t StackInit (Stack_t* stk, size_t capacity)
{
    Verificator (stk, mode);
    stk -> size = 0;
    stk -> data = (int*) calloc (capacity, sizeof(int));
    stk -> capacity = capacity;
    return CORRECT;
}

Err_t StackPush (Stack_t* stk, int value)
{

    Verificator (stk, mode);

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

    return CORRECT;
}

Err_t StackPop (Stack_t* stk, int *x)
{
    Verificator (stk, mode);
    *x = stk -> data [stk -> size - 1];
    return CORRECT;
}

void StackDestroy (Stack_t* stk)
{
    Verificator (stk, mode);
    free(stk -> data);
    stk -> data = NULL;
    stk -> size = 0;
    stk -> capacity = 0;
    //stk = NULL;

}

