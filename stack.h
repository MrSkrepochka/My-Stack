#ifndef STACK_H
#define STACK_H

#define WRONG_VALUE_CONST 0x111AC

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>

#include "stack.h"

#include "stack.h"



extern int valueForPush = WRONG_VALUE_CONST; //70060

struct Stack_t{
    int* data;
    size_t size;
    size_t capacity;

};

enum Err_t {
    CORRECT = 0,
    STACK_NOT_FOUND = 1,
    STACK_ALREADY_EXISTS = 2,
    WRONG_CAPACITY = 3,
    WRONG_VALUE = 4,
    EMPTY_STACK = 5,

};

enum Commands{
    WRONG_COMMAND = 0,
    EXIT = 1,
    INIT = 2,
    PUSH = 3,
    POP = 4,
    DESTROY = 5
};

//#include "Errors.h"

extern Commands mode = WRONG_COMMAND;

Err_t StackInit (Stack_t*, size_t);
Err_t StackPush (Stack_t* stk, int value);
Err_t StackPop (Stack_t* stk, int*);
void StackDestroy (Stack_t* stk);


#endif
