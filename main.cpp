#include "Errors.h"

int main()
{
    Stack_t stk1 = {};

    while (Console(&stk1) == true)
        continue;

    if (&stk1 != NULL)
        StackDestroy (&stk1);

    return 0;
}
