
#include <stdio.h>
#include "nr_micro_shell.h"

void your_command_funtion(char argc, char *argv)
{
    printf("run your_com\r\n");
}

const static_cmd_st static_cmd[] =
{
   {"your_com", your_command_funtion},
   {"\0", NULL}
};
