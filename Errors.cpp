#include "Errors.h"

int nErrors = 0;
Err_t global_error = CORRECT;


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
    fprintf(stdout,"\n\t\t}\n");
}

void PrintError (Err_t err)
{
    switch (err)
    {
        case CORRECT:
            break;
        case STACK_NOT_FOUND:
            fprintf(stdout, "STACK_NOT_FOUND\n");
            break;
        case STACK_ALREADY_EXISTS:
            fprintf(stdout, "STACK_ALREADY_EXISTS\n");
            break;
        case WRONG_CAPACITY:
            fprintf(stdout, "WRONG_CAPACITY\n");
            break;
        case WRONG_VALUE:
            fprintf(stdout, "WRONG_VALUE\n");
            break;
        case EMPTY_STACK:
            fprintf(stdout, "EMPTY_STACK\n");
            break;
        default:
            break;
    }

    //*err = CORRECT;
}

Err_t StackVerify(Stack_t* stk, Commands mode, int ValueForPush)
{

    assert (stk);
    switch (mode)
    {
    case POP:
        if (stk -> data == NULL)
            return STACK_NOT_FOUND;
        if (stk -> size <= 0 )
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
        if (ValueForPush == WRONG_VALUE_CONST)
            return WRONG_VALUE;
        break;
    default:
        break;
    }
    return CORRECT;
}

Err_t Verificator (Stack_t* stk, Commands mode, int value)
{
    Err_t code = StackVerify(stk, mode, value);
    if (code != CORRECT)
    {
        fprintf(stdout, "Program failed:");
        PrintError(code);
        if (code != STACK_NOT_FOUND)
            StackDump(stk);
    }
    return code;
}
