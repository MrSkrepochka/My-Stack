#include "Errors.h"

const int CapacityDoubler = 2;


Err_t StackInit (Stack_t* stk, size_t capacity)
{
    Commands mode = INIT;

    size_t oldCapacity = stk -> capacity;

    stk -> capacity = capacity;
    //Verificator (stk, INIT);
    VERIFY(stk, mode, WRONG_VALUE_CONST);
    if (global_error == CORRECT)
        stk -> data = (int*) calloc (capacity, sizeof(int));
    else
        {
            stk -> capacity = oldCapacity;
        }

    return global_error;
}

Err_t StackPush (Stack_t* stk, int value)
{
    Commands mode = PUSH;
    VERIFY(stk, mode, value);
    //Verificator (stk, PUSH, value);
    if (global_error != CORRECT)
        return global_error;

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

int StackPop (Stack_t* stk)
{
    VERIFY(stk, POP, WRONG_VALUE_CONST);
    if (global_error == CORRECT)
    //if (Verificator (stk, POP) == CORRECT)
    {
    int x = stk -> data [stk -> size - 1];
    stk -> data [stk -> size -1] = 0;
    stk -> size--;
    return x;
    }
    return -1;
}

Err_t StackDestroy (Stack_t* stk)
{
    Commands mode = DESTROY;
    VERIFY(stk, mode, WRONG_VALUE_CONST);
    if (global_error == CORRECT)
    {
    //Verificator (stk, DESTROY);
    free(stk -> data);
    stk -> data = NULL;
    stk -> size = 0;
    stk -> capacity = 0;
    return CORRECT;
    }
    return global_error;
    //stk = NULL;

}

