#include "Errors.h"

void StackDump (Stack_t* stk)
{
    fprintf(stdout, "StackDump called from %s in %s:%d\n\t", __func__, __FILE__, __LINE__ );
    fprintf(stdout, "stack [0x%p]\n\t", stk);
    fprintf(stdout, "size = %zu\n\t\t", stk -> size);
    fprintf(stdout, "capacity = %zu\n\t\t", stk -> capacity);
    fprintf(stdout, "data [0x%p]\n\t\t{\n\n\t\t\t", stk -> data);
    for (size_t element = 0; element < stk -> size; element++)
    {
        fprintf(stdout, "* [%zu] = %d\n\t\t\t", element, stk -> data[element]);
    }
    fprintf(stdout,"\n\t\t}");
}

void PrintError (Err_t err)
{
    switch (err)
    {
        case CORRECT:
            break;
        case STACK_NOT_FOUND:
            fprintf(stderr, "STACK_NOT_FOUND\n");
            break;
        case STACK_ALREADY_EXISTS:
            fprintf(stderr, "STACK_ALREADY_EXISTS\n");
            break;
        case WRONG_CAPACITY:
            fprintf(stderr, "WRONG_CAPACITY\n");
            break;
        case WRONG_VALUE:
            fprintf(stderr, "WRONG_VALUE\n");
            break;
        case EMPTY_STACK:
            fprintf(stderr, "EMPTY_STACK\n");
            break;
        default:
            break;
    }

    //*err = CORRECT;
}

Err_t StackVerify(Stack_t* stk, Commands mode1, int ValueForPush1)
{
    if (!stk)
        return STACK_NOT_FOUND;

    switch (mode1)
    {
    case POP:
        if (stk -> size == 0 )
            return EMPTY_STACK;
        break;
    case INIT:
        if (stk -> data != NULL)
            return STACK_ALREADY_EXISTS;
        if (stk -> capacity <= 0)
            return WRONG_CAPACITY;
        break;
    case DESTROY:
        if (stk -> data == NULL)
            return STACK_NOT_FOUND;
        break;
    case PUSH:
        if (stk -> data == NULL)
            return STACK_NOT_FOUND;
        if (ValueForPush1 == WRONG_VALUE_CONST || isfinite (ValueForPush1) == 0)
            return WRONG_VALUE;
            break;
    default:
        break;
    }
    return CORRECT;
}

void Verificator (Stack_t* stk, Commands mode1)
{
    Err_t code = StackVerify(stk, mode1);
    if (code != CORRECT)
        PrintError(code);
    if (code != STACK_NOT_FOUND)
        StackDump(stk);
}
