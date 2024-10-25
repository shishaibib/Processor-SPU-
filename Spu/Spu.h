#include "..\Stack\Stack.h"
enum Instruction_Codes
{
    PUSH_CODE  = 0x01, //01
    POP_CODE   = 0x10, //10
    SUB_CODE   = 0x02, //2
    ADD_CODE   = 0x03, //3
    MUL_CODE   = 0x07, //7
    DIV_CODE   = 0x06, //6
    PUSHR_CODE = 0x11, //11

    JB_CODE    = 0x09, //9

    DUMP_CODE  = 0x08, //8
    OUT_CODE   = 0x05, //5 
    HLT_CODE   = 0x44  //44 в 16 сист
};

enum Buffer_Parametrs
{
    CODE_BUFFER_SIZE = 40,
    CMD_MAX_SIZE = 10
};

struct spu_t
{
    int* code;
    stk_t stk;
    int ip;
    int* registers;
};

struct assembly_t
{



};

void Run();
void Spu_Init(spu_t *spu);
void Dump_Spu(spu_t *spu);