#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
typedef int stack_elem_t;
typedef int hash_t;
typedef double cannary_t;

struct stk_t
{
    hash_t hash;
    hash_t saved_hash;
    stack_elem_t* data;
    size_t size;
    size_t capacity;
};

enum STACK_CONSTS
{
    DATA_CANNARY = -444,
    POISON_NUMBER = -666,
    MEMORY_MULTIPLY_COEFICIENT = 4,
    MEMORY_REDUCE_COEFICIENT = 2
};

int Push_Stack(struct stk_t *stk, stack_elem_t pushed_element);
int Pop_Stack(struct stk_t *stk);
int Init_Stack(stk_t* stk);
void Dump_Stack(stk_t* stk);
int Dtor_Stack(stk_t* stk);
int Reallocate_Memory(struct stk_t *stk);
int Reduce_Free_Memory(struct stk_t *stk);
//int Calculate_Hash(struct stk_t *stk);