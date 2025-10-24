#include "Console.h"


void Console(Stack_t* stk, Stack_t* adr_stk, int* byte_code, size_t number_of_elements)
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
            VERIFY(stk, 2, (int) capacity, "main");
            if (global_error != CORRECT)
                return;

            StackInit (stk, capacity);
            IP += 2;
            break;
        case 3: //PUSH
            value = byte_code[IP + 1];
            VERIFY(stk, 3, value, "main");

            if (global_error != CORRECT)
                return;

            StackPush (stk, value);
            IP += 2;

            break;
        case 4: //POP

            VERIFY(stk, 4, 0, "main");
            if (global_error != CORRECT)
                return;
            PopValue = StackPop(stk);
            fprintf(stdout, "%d\n", PopValue);
            IP++;
            break;

        case 6: //ADD
            VERIFY(stk, 6, 0, "main");
            if (global_error != CORRECT)
                return;
            StackAdd(stk);
            IP++;
            break;

        case 7: //MUL
            VERIFY(stk, 7, 0, "main");
            if (global_error != CORRECT)
                return;
            StackMul(stk);
            IP++;
            break;

        case 8: //DIV
            VERIFY(stk, 8, 0, "main");
            if (global_error != CORRECT)
                return;
            StackDiv(stk);
            IP++;
            break;
        case 9: // JB
            VERIFY(stk, 6, 0, "main"); // как у ADD
            if (StackPop(stk) > StackPop(stk))
                IP = (size_t) byte_code[IP + 1];
            else
                IP += 2;
            break;

        case 10: //PUSHR
            VERIFY(stk, 10, byte_code[IP + 1],"main");
            if (global_error != CORRECT)
                return;
            StackPush(stk, Registers[byte_code[IP +1]]);
            IP+=2;
            break;

        case 11: //POPR
            VERIFY(stk, 4, 0, "main");
            if (global_error != CORRECT)
                return;
            Registers[byte_code[IP+1]] = StackPop(stk);
            IP += 2;
            break;

        case 12: //JBE
            VERIFY(stk, 6, 0,"main"); // как у ADD
            if (StackPop(stk) >= StackPop(stk))
                IP = (size_t) byte_code[IP + 1];
            else
                IP += 2;
            break;

        case 13: // JE
            VERIFY(stk, 6, 0,"main"); // как у ADD
            if (StackPop(stk) == StackPop(stk))
                IP = (size_t) byte_code[IP + 1];
            else
                IP += 2;
            break;

        case 14: // JA
            VERIFY(stk, 6, 0,"main"); // как у ADD
            if (StackPop(stk)  < StackPop(stk))
                IP = (size_t) byte_code[IP + 1];
            else
                IP += 2;
            break;

        case 15: // CALL
            if (adr_stk -> data == NULL)
                StackInit(adr_stk, 5);

            StackPush(adr_stk, (int) IP + 2);
            IP = (size_t) byte_code[IP + 1];
            break;

        case 16: // RET
            VERIFY(adr_stk, 16, 0, "address");
            IP = (size_t) StackPop(adr_stk);
            break;

        case 5: //DESTROY
            VERIFY(stk, 5, 0, "main");
            if (global_error != CORRECT)
                return;
            StackDestroy(stk);
            IP++;
            break;
        case 1: //EXIT
            if (stk -> data != NULL)
                StackDestroy(stk);
            if (adr_stk -> data != NULL)
                StackDestroy(adr_stk);
            IP++;
            return;
            break;
        default:
            break;
        }
    }

    return;
}
