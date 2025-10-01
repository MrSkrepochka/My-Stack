#include "Console.h"


bool Console(Stack_t* stk)
{
    int x = 0;

    size_t capacity = 0;

    char command[5] ="";

    bool Indicator = true;

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

        Indicator = true;
        break;
    case PUSH:

        //fprintf (stdout, "Enter integer value\n");
        fscanf (stdin,"%d", &valueForPush);
        StackPush (stk, valueForPush);

        Indicator = true;
        break;
    case POP:
        StackPop (stk, &x);
        Indicator = true;
        break;
    case DESTROY:
        StackDestroy(stk);
        Indicator = true;
        break;
    case EXIT:
        if (stk != NULL)
            StackDestroy(stk);
        Indicator = false;
        break;
    case WRONG_COMMAND:
        fprintf (stdout, "Incorrect input\n");
        break;
    default:
        break;
    }

    return Indicator;
}
