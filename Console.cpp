#include "Console.h"


bool Console(Stack_t* stk)
{
    int valueForPush = WRONG_VALUE_CONST;
    int PopValue = 0;
    size_t capacity = 0;
    //char* command = (char*) calloc (5, sizeof(char));

    char command[5] = "";


    Commands mode = WRONG_COMMAND;

    fprintf(stdout, "Enter command\n");

    fscanf(stdin, "%4s", command);

    if (strcmp (command, "INIT")== 0 )
        mode = INIT;

    if (strcmp (command, "PUSH")== 0 )
        mode = PUSH;

    if (strcmp (command, "POP")== 0 )
        mode = POP;

    if (strcmp (command, "DEL")== 0 )
        mode = DESTROY;

    if (strcmp (command, "EXIT")== 0 )
        mode = EXIT;

    switch (mode)
    {

    case INIT:
        fprintf (stdout,"Enter stack capacity\n");

        fscanf (stdin, "%zu", &capacity);
        StackInit (stk, capacity);
        if (global_error != CORRECT)
            nErrors++;
        return true;
        break;
    case PUSH:

        fprintf (stdout, "Enter integer value\n");
        fscanf (stdin,"%d", &valueForPush);
        StackPush (stk, valueForPush);
        if (global_error != CORRECT)
            {
            nErrors++;
            return true;
            }
        break;
    case POP:
        PopValue = StackPop (stk);
        if (global_error != CORRECT)
            {
            nErrors++;
            return true;
            }
        fprintf(stdout, "%d\n", PopValue);
        return true;
        break;
    case DESTROY:
        StackDestroy(stk);
        if (global_error != CORRECT)
            nErrors++;

        return true;
        break;
    case EXIT:
        if (stk -> data != NULL)
            StackDestroy(stk);
        return false;
        break;
    case WRONG_COMMAND:
        fprintf (stdout, "Incorrect iput\n");
        nErrors++;
        return true;
        break;
    default:
        break;
    }
    //free(command);
    return true;
}
