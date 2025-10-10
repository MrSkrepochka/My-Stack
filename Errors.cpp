#include "Errors.h"

int nErrors = 0;
Err_t global_error = CORRECT;

void PrintError (Err_t err)
{
    switch (err)
    {
        case CORRECT:
            break;
        case STACK_NOT_FOUND:
            fprintf(stdout, "Attempting to interact with an unexisting stack\n");
            break;
        case STACK_ALREADY_EXISTS:
            fprintf(stdout, "Attempting to initialize an existing stack\n");
            break;
        case WRONG_CAPACITY:
            fprintf(stdout, "Attempting to initialize a stack with incorrect capacity\n");
            break;
        case EMPTY_STACK:
            fprintf(stdout, "Function requires more arguments than your stack has\n");
            break;
        case DIV_0:
            fprintf(stdout, "Attempting to divide by 0\n");
        default:
            break;
    }

    //*err = CORRECT;
}

Err_t StackVerify(Stack_t* stk, int mode, int Value)
{
    switch (mode)
    {
    case 4: // POP
        if (stk -> data == NULL)
            return STACK_NOT_FOUND;
        if (stk -> size == 0 )
            return EMPTY_STACK;
        break;
    case 2: // INIT
        if (stk -> data != NULL)
            return STACK_ALREADY_EXISTS;
        if ( Value <= 0)
            return WRONG_CAPACITY;
        break;
    case 5: // DESTROY
        if (stk -> data == NULL)
            return STACK_NOT_FOUND;
        break;
    case 3: // PUSH
        if (stk -> data == NULL)
            return STACK_NOT_FOUND;
        break;
    case 6: // ADD
        if (stk -> data == NULL)
            return STACK_NOT_FOUND;
        if (stk -> size <2)
            return EMPTY_STACK;

        break;
    case 7: //MUL
        if (stk -> data == NULL)
            return STACK_NOT_FOUND;
        if (stk -> size <2)
            return EMPTY_STACK;
    case 8: // DIV
        if (stk -> data == NULL)
            return STACK_NOT_FOUND;
        if (stk -> size <2)
            return EMPTY_STACK;
        if (stk -> data[stk ->size - 1] == 0)
            return DIV_0;
        break;
    default:
        break;
    }
    return CORRECT;
}


