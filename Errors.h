#ifndef ERRORS_H
#define ERRORS_H

#include "Console.h"



#define VERIFY(stk, mode) (if ( code = (StackVerify (stk, mode, valueForPush)) != CORRECT) DUMP (code))
#define DUMP(code, stk) (fprintf (stderr, "Program failed: %s", PrintError(code)); \
                             if (code != STACK_NOT_FOUND) StackDump (stk))

void StackDump (Stack_t* stk);
void PrintError (Err_t errorCode);
void Verificator (Stack_t* stk, Commands mode1);

Err_t StackVerify (Stack_t* stk, Commands mode1,  int ValueForPush1 = WRONG_VALUE_CONST);

#endif
