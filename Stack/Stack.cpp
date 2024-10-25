#include "Stack.h"

int Init_Stack(stk_t* stk)
{
    stk->capacity = 8;
    stk->data = (stack_elem_t*)calloc(stk->capacity /*+ 2*/, sizeof(stack_elem_t));
   /* stk->data[0] = DATA_CANNARY;
    stk->data += 1; */

    //stk->data[stk->capacity + 1] = DATA_CANNARY; 
    stk->size = 0;
    for(size_t i = 0; i < stk->capacity; i++)
        stk->data[i] = POISON_NUMBER;

    Dump_Stack(stk);
    return 0;
}

int Dtor_Stack(stk_t* stk)
{
    stk->size = 0;
    stk->capacity = 0; 
    free(stk->data);                                     
    return 0;
}     

int Push_Stack(struct stk_t *stk, stack_elem_t pushed_element)          
{
    printf("New element: %d \n", pushed_element);
    stk->data[stk->size] = pushed_element;
    stk->size ++;
    Reallocate_Memory(stk);
    Reduce_Free_Memory(stk);
    Dump_Stack(stk);
    return 0;
}

int Pop_Stack(struct stk_t *stk)
{
    printf("size before pop = %d \n",stk->size);
    stack_elem_t pop_element = stk->data[stk->size - 1];
    stk->data[stk->size - 1] = POISON_NUMBER;
    stk->size --;
    Dump_Stack(stk);
    return pop_element;  
}

int Reallocate_Memory(struct stk_t *stk)
{
    if (stk->size == stk->capacity)
    {

        printf("size = %d == capacity = %d \n", stk->size, stk->capacity);
        size_t new_capacity = stk->capacity * MEMORY_MULTIPLY_COEFICIENT;

        stk->data = (stack_elem_t*)realloc(stk->data, new_capacity * sizeof(stack_elem_t) /*+ 2 * sizeof(cannary_t)*/);
        //stk->data += 1;
        //stk->data[stk->capacity + 1] = DATA_CANNARY;

        stk->capacity = new_capacity;
        //stk->data[stk->capacity + 1] = DATA_CANNARY;
        /*printf("data = %p \n",  stk->data);
        printf("(*stk)->size = %d \n", stk->size);
        printf("data[0] = %d \n",  stk->data[0]);*/

        for(size_t i = stk->size; i < stk->capacity; i++)
            stk->data[i] = POISON_NUMBER;
        
        if (stk->data == NULL)
        {
            printf("error : memory reallocation failed");
            return 0;
        }

        Dump_Stack(stk);
    }

    return 0;            
}

int Reduce_Free_Memory(struct stk_t *stk)
{   

    if(stk->size <= 0.25 * stk->capacity)
    {
        printf("capacity before reduce : %d \n", stk->capacity);
        Dump_Stack(stk);
        size_t new_capacity = stk->capacity / MEMORY_REDUCE_COEFICIENT;

        for(size_t i = stk->capacity ; i > new_capacity; i--)
        {
            stk->data[i] = 0;
        }

        stk->capacity = new_capacity;

        stk->data = (stack_elem_t*)realloc(stk->data, new_capacity * sizeof(stack_elem_t) /*+ 2 * sizeof(cannary_t)*/);
        //printf("%d \n", new_capacity * sizeof(stack_elem_t) + 2 * sizeof(cannary_t));
        //stk->data[0] = DATA_CANNARY;

        /*stk->data += 1;
        stk->data[stk->capacity + 1] = DATA_CANNARY;*/
         
        Dump_Stack(stk); 
    }

    if (stk->data == NULL)
        {
            printf("error : memory reallocation failed");
            return 0;
        }

    printf("capacity after reduce : %d \n", stk->capacity);
    return 0;
}

/*int Calculate_Hash(struct stk_t *stk)
{
    stk->hash = 5381;
    for(size_t i = 0; i < stk->capacity; i++)
    {
       stk->hash = (stk->hash) * 31 ^ (int64_t)(stk->data[i]);
       printf("hash(%d) = %ll \n", i, stk->hash);
    }
    stk->saved_hash = stk->hash;
    printf("saved hash = %ll \n", stk->saved_hash);

    Dump_Stack(stk);
    return 0;
}*/

void Dump_Stack (stk_t* stk)
{
    printf("-----------------------------------------------------------------------\n");
    printf("size = %d \n",stk->size);
    printf("capacity = %d \n",stk->capacity);
    printf("data[adress : %p] \n", stk->data);
    //printf("left cannary = %d \n", stk->data[-1]);
    for(size_t i = 0; i < stk->capacity; i++)
        printf("data[%d] = %d \n", i, stk->data[i]);
    //printf("right cannary = %d \n", stk->data[stk->capacity + 1]);
    printf("-----------------------------------------------------------------------\n");
}

/*int Compare_Hash(stk_t* stk)
{
    if(stk->saved_hash != stk ->hash)
    {
        printf("hash error");
        abort();
    }
}*/ 