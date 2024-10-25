#include "Spu.h"
int Assemly_Compile()
{
    FILE *source   = fopen("SourceFile.txt"  , "r");
    FILE *commands = fopen("CommandsFile.txt", "w");

    if(source != NULL)
    {
        char cmd[CMD_MAX_SIZE] = {};

        int var = 0;
        int ip  = 0;
        int arg = 0;
        int code[CODE_BUFFER_SIZE] = {};

        while(1 && cmd != EOF)
        {
        fscanf(source, "%s", cmd);

            if(strcmp(str, "push") == 0)
            {
                code[ip++] = PUSH_CODE;
                fscanf(source, "%d", arg);
                code[ip++] = arg;
            }

       else if(strcmp(str, "pop") == 0)
            {
                code[ip++] = POP_CODE;
            }

       else if(strcmp(str, "add") == 0)
            {
                code[ip++] = ADD_CODE;
            }

       else if(strcmp(str, "sub") == 0)
            {
                code[ip++] = SUB_CODE;
            }
       else
            {
                printf("Syntax error pos: %d name: %s", ip, cmd);
                return 0;
            }

        }
        
    }

    else
    {
        printf("FILE ERROR, CHECK YOUR FILE");
        return 0;
    }

    fclose(source);
    fclose(commands);

    return 0;

}