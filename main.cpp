#include "Console.h"

const int WRONG_VALUE_CONST =0x11A15ED;
int Registers[16];
void RegInit(int* array, size_t size);

int main()
{
    RegInit(Registers, 16);

    FILE* file = fopen ("ByteCode.txt", "r");

    size_t number_of_elements = 0;
    fscanf(file, "%zu", &number_of_elements );
    int* byte_code = (int*) calloc (number_of_elements, sizeof (int));
    for (size_t counter = 0; counter < number_of_elements; counter++)
    {
        fscanf(file, "%d", &(byte_code[counter]));
    }

    /*for (size_t i = 0; i < number_of_elements; i++ )
    {
        fprintf(stdout, "%d ", byte_code[i]);
    }*/

    Stack_t stk1 = {NULL, 0, 0};
    Stack_t adr_stk = {NULL, 0, 0};


    Console(&stk1, &adr_stk, byte_code, number_of_elements);

    fclose(file);
    return 0;
}

void RegInit(int* registers, size_t size)
{
    for (size_t counter = 0; counter < size; counter++)
    {
        registers[counter] = WRONG_VALUE_CONST;
    }
}
