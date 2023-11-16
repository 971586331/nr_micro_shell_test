
#include <stdio.h>
#include <stdlib.h>
#include "nr_micro_shell.h"
#include <elog.h>

void elog_test(char argc, char *argv)
{
    log_a("Hello EasyLogger!");
    log_e("Hello EasyLogger!");
    log_w("Hello EasyLogger!");
    log_i("Hello EasyLogger!");
    log_d("Hello EasyLogger!");
    log_v("Hello EasyLogger!");
}

void elog_level_funtion(char argc, char *argv)
{
    if(argc < 2) {
        printf("Error: too few parameters!\r\n");
        return;
    }
    int value = atoi(&(argv[argv[1]]));
		printf("value = %d \r\n", value);
    elog_set_filter_lvl(value);
}

void your_command_funtion(char argc, char *argv)
{
    printf("run your_com\r\n");
}

const static_cmd_st static_cmd[] =
{
   {"your_com", your_command_funtion},
   {"elog_test", elog_test},
   {"elog_level", elog_level_funtion},
   {"\0", NULL}
};
