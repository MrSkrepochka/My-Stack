#ifndef STACK_H
#define STACK_H

#include "Errors.h"



Err_t StackInit (Stack_t*, size_t);
Err_t StackPush (Stack_t* stk, int value);
int StackPop (Stack_t* stk);
Err_t StackDestroy (Stack_t* stk);


#endif
