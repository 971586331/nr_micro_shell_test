
#include <stdio.h>
#include <stdlib.h>
#include "nr_micro_shell.h"
#include <elog.h>
#include <flashdb.h>
#include "main.h"
#include <string.h>

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

void flashdb_set_funtion(char argc, char *argv)
{
    if(argc < 2) {
        printf("Error: too few parameters!\r\n");
        return;
    }
		printf("set username = %s \r\n", &(argv[argv[1]]));
    /* It will create new KV node when "temp" KV not in database. */
    fdb_kv_set(&kvdb, "username", &(argv[argv[1]]));
}

void flashdb_get_funtion(char argc, char *argv)
{
    /* GET the KV value */
    char *return_value, temp_data[10] = { 0 };

    /* Get the "temp" KV value.
        * NOTE: The return value saved in fdb_kv_get's buffer. Please copy away as soon as possible.
        */
    return_value = fdb_kv_get(&kvdb, "username");
    /* the return value is NULL when get the value failed */
    if (return_value != NULL) {
        strncpy(temp_data, return_value, sizeof(temp_data));
        printf("get the 'username' value is: %s\r\n", temp_data);
    }
}

const static_cmd_st static_cmd[] =
{
   {"your_com", your_command_funtion},
   {"elog_test", elog_test},
   {"elog_level", elog_level_funtion},
   {"elog_level", elog_level_funtion},
   {"flashdb_set", flashdb_set_funtion},
   {"flashdb_get", flashdb_get_funtion},
   {"\0", NULL}
};
