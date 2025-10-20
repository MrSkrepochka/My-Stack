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
            break;
        case EMPTY_REG:
            fprintf(stdout, "Attempting to push a value from an empty register\n");
        case NOWHERE_TO_RETURN:
            fprintf(stdout, "Return function has no address to go to\n");
            break;
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

    case 10: // PUSHR
        if (stk -> data == NULL)
            return STACK_NOT_FOUND;
        if (Registers[Value] == WRONG_VALUE_CONST)
            return EMPTY_REG;
        break;

    case 16: //RET
        if (stk -> size <= 0)
            return NOWHERE_TO_RETURN;
        break;
        
    default:
        break;
    }
    return CORRECT;
}


