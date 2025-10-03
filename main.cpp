#include "Console.h"

int main()
{
    Stack_t stk1 = {NULL, 0, 0};

    while (Console(&stk1) == true)
        continue;

    if(stk1.data != NULL)
    {
        StackDestroy (&stk1);
    }
    return 0;
}
