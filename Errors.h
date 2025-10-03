#ifndef ERRORS_H
#define ERRORS_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>

#define WRONG_VALUE_CONST 0x11A15ED


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
    DESTROY = 5,
    ADD = 6,

};

#define VERIFY(stk, mode, value) \
    do { \
        Err_t __code = StackVerify(stk, mode, value); \
        if (__code != CORRECT) \
            {DUMP(__code, stk);} else \
            {global_error = CORRECT;} \
    } while (0)

#define DUMP(code, stk) \
    do { \
        fprintf(stdout, "Program failed: "); \
        PrintError(code); \
        if (code != STACK_NOT_FOUND) \
            { \
                fprintf(stdout, "StackDump called from %s in %s:%d\n\t", __func__, __FILE__, __LINE__ ); \
                fprintf(stdout, "stack [0x%p]\n\t", stk); \
                fprintf(stdout, "size = %zu\n\t\t", stk -> size); \
                fprintf(stdout, "capacity = %zu\n\t\t", stk -> capacity); \
                fprintf(stdout, "data [0x%p]\n\t\t{\n\n\t\t\t", stk -> data); \
                for (size_t element = 0; element < stk -> size; element++) \
                {   \
                    fprintf(stdout, "* [%zu] = %d\n\t\t\t", element, stk -> data[element]); \
                }   \
                 fprintf(stdout,"\n\t\t}\n"); \
            } \
        global_error = code; \
    } while (0)

extern int nErrors;
extern Err_t global_error;

void StackDump (Stack_t* stk);
void PrintError (Err_t errorCode);
Err_t Verificator (Stack_t* stk, Commands mode, int value = WRONG_VALUE_CONST);

Err_t StackVerify (Stack_t* stk, Commands mode,  int ValueForPush);

#endif
