#ifndef STACK_H
#define STACK_H

#include "Errors.h"



void StackInit (Stack_t* , size_t);
void StackPush (Stack_t* stk, int value);
int StackPop (Stack_t* stk);
void StackDestroy (Stack_t* stk);

void StackDiv (Stack_t* stk);
void StackAdd (Stack_t* stk);
void StackMul (Stack_t* stk);

#endif
