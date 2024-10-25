//#include "..\Stack\Stack.h"
#include "Spu.h"

void Run()
{
 // - spu init ----------------------------------------------------- 
    spu_t spu = {};
    Spu_Init(&spu);
    Dump_Spu(&spu);
 /* spu_t spu = {};
    &spu->code = (int*)calloc(CODE_BUFFER_SIZE, sizeof(int));
    &spu->code = {PUSH_CODE, 4, PUSH_CODE, 7, SUB_CODE , OUT_CODE, HLT_CODE};
    int ip = 0;*/
// -----------------------------------------------------------------
    while (1)
    {                              
                    
    }
    
}

void Dump_Spu(spu_t *spu)
{
    printf("\n---------------Spu dump begin ----------------------\n");

    printf("\n-----------------Stack_Info-------------------------\n");
    Dump_Stack(spu.stk);
    printf("\n----------------------------------------------------\n");

    printf("\n-----------------instructions-----------------------\n");

    for(int i = 0; i < CODE_BUFFER_SIZE; i++)
        printf("%2d ", i);

    printf("\n");

    for(int i = 0; i < CODE_BUFFER_SIZE; i++)
        printf("%2d ", spu->code[i]);

    printf("\n");

    for(int i = 0; i < CODE_BUFFER_SIZE; i++)
        printf("--", spu->code[i]);
    printf("^^\n");   
  
    /*ЕБАШЬ ДЕБАГ САНЯ*/
    /*НЕ ЕБЛАНЬ*/
    /*НЕ ЕБЛАНЬ*/
    /*нЕ ЕБЛАНЬьььььььььььььььььььььььььььььььььььььььььььььььььььььььььььььььь*/

}

void Spu_Init(spu_t *spu)
{
    spu_t->stk = {};
    spu->code = (int*)calloc(CODE_BUFFER_SIZE, siseof(int));
    Init_Stack(&spu.stk);
    ReadCommandsFile(&spu);
}

void ReadCommandsFile(spu_t *spu)
{
    FILE *commands = fopen("./Assembly/CommandsFile.txt", "r");

    if (commands == NULL)
    {
        printf ("Not find CommandsFile.txt\n");
    }

    
}



/*
if(spu->code[&spu->ip] == PUSH_CODE)                             ебануть через свич и не ебать мозги
        {
            int arg = 0;
            arg = spu->code[&spu->ip + 1];
            Push_Stack(&spu.stk, arg);
            ip += 2;
        }

        else if(spu->code[ip] == SUB_CODE)
        {
            int a = Pop_Stack(&spu.stk);
            int b = Pop_Stack(&spu.stk);

            Push_Stack(&spu.stk, b - a);
            ++ip;
        }

        else if(spu->code[ip] == OUT_CODE)
        {
            int arg = Pop_Stack(&spu.stk);                                                          // может появиться косяк
            printf("Out elem: %d \n", arg);
            ++ip;
        }
R ip register
        else if(spu->code[ip] == HLT_CODE)
        {
            Dtor_Stack(&spu.stk);
            ip = 0;
            break;
        }

        else
        {
            printf("SNTXERR : %x", spu->code[ip]);
            Dump_Stack(&spu.stk);
            break;
        }
*/