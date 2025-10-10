#include "Console.h"


void Console(Stack_t* stk, int* byte_code, size_t number_of_elements)
{
    size_t IP = 0;
    while (IP < number_of_elements)
    {
        int value = 0;
        int PopValue = 0;
        size_t capacity = 0;
        int command = byte_code[IP];

        switch (command)
        {

        case 2: //INIT
            capacity = (size_t) byte_code[IP + 1];
            VERIFY(stk, 2, (int) capacity);
            if (global_error != CORRECT)
                return;

            StackInit (stk, capacity);
            IP += 2;
            break;
        case 3: //PUSH
            value = byte_code[IP + 1];
            VERIFY(stk, 3, value);

            if (global_error != CORRECT)
                return;

            StackPush (stk, value);
            IP += 2;

            break;
        case 4: //POP

            VERIFY(stk, 4, 0);
            if (global_error != CORRECT)
                return;
            PopValue = StackPop(stk);
            fprintf(stdout, "%d\n", PopValue);
            IP++;
            break;

        case 6: //ADD
            VERIFY(stk, 6, 0);
            if (global_error != CORRECT)
                return;
            StackAdd(stk);
            IP++;
            break;

        case 7: //MUL
            VERIFY(stk, 7, 0);
            if (global_error != CORRECT)
                return;
            StackMul(stk);
            IP++;
            break;

        case 8: //DIV
            VERIFY(stk, 8, 0);
            if (global_error != CORRECT)
                return;
            StackDiv(stk);
            IP++;
            break;

        case 5: //DESTROY
            VERIFY(stk, 5, 0);
            if (global_error != CORRECT)
                return;
            StackDestroy(stk);
            IP++;
            break;
        case 1: //EXIT
            if (stk -> data != NULL)
                StackDestroy(stk);
            IP++;
            return;
            break;
        default:
            break;
        }
    }

    return;
}
