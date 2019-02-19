#include "tests.h"


int test_main(){

    int li_rtn;

    li_rtn = test1();

    return li_rtn;

}

int test1(){

    c_string_t c_str, c_str2;

    c_string_create(&c_str);
    c_string_create(&c_str2);

    c_string_load(&c_str, "Las mil y unaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa ");

    printf("c_str: %ld + %ld + %ld + \"%s\"\n",    c_string_get_length(&c_str),
                                            c_string_get_mem_size(&c_str),
                                            c_string_get_unused_mem(&c_str),
                                            c_string_get_str(&c_str));
    c_string_load(&c_str2, "Noches");

    printf("c_str2: %ld + %ld + %ld + \"%s\"\n",    c_string_get_length(&c_str2),
                                            c_string_get_mem_size(&c_str2),
                                            c_string_get_unused_mem(&c_str2),
                                            c_string_get_str(&c_str2));

    c_string_append_c_string(&c_str , &c_str2);

    printf("c_str: %ld + %ld + %ld + \"%s\"\n",    c_string_get_length(&c_str),
                                            c_string_get_mem_size(&c_str),
                                            c_string_get_unused_mem(&c_str),
                                            c_string_get_str(&c_str));

    return 0;

}
