#include "c_ut.h"

/// Funciones privadas

static int __ts_allocate_mem(c_testsheet_t* ts_ptr, int number_of_tests){

    ts_ptr->_ut_ptr_arr = (c_ut_ptr_t*  ) malloc(sizeof(c_ut_ptr_t) * number_of_tests);

    if ( !ts_ptr->_ut_ptr_arr)
        return MEM_ERROR_UT_PTR;

    ts_ptr->_ut_data_arr = (c_ut_xdata_t* ) malloc(sizeof(c_ut_xdata_t) * number_of_tests);

    if ( !ts_ptr->_ut_data_arr){

        free(ts_ptr->_ut_ptr_arr);
        return MEM_ERROR_UT_PRM;

    }

    return EXIT_SUCCESS;

}

static void __ts_load_execution_data_struct (

                                                c_testsheet_t*  ts_ptr,
                                                const char*     test_name
                                                /*Se agregaran mas atributos a futuro*/
                                            ){


    c_ut_xdata_t * lp_data = (ts_ptr->_ut_data_arr + ts_ptr->_curr_not);

    strcpy( lp_data->_test_name , test_name );

}

/// Fin Funciones Privadas

int init_testsheet(c_testsheet_t* ts_ptr){

    if (ts_ptr == NULL)
        return NULL_TESTSHEET_PTR;

    ts_ptr->_max_not            = 0;
    ts_ptr->_curr_not           = 0;
    ts_ptr->_ut_ptr_arr         = NULL;
    ts_ptr->_ut_data_arr        = NULL;

    return INIT_SUCCESS;

}

int create_testsheet(c_testsheet_t* ts_ptr, const int number_of_tests ){

    int li_rtn;

    if (number_of_tests <= 0 )
        return INVALID_NUMBER_OF_TESTS;

    if (ts_ptr == NULL)
        return NULL_TESTSHEET_PTR;

    if (ts_ptr->_max_not != 0 )
        return INIT_TESTSHEET_FIRST;

    li_rtn = __ts_allocate_mem(ts_ptr, number_of_tests);

    if ( li_rtn != 0 )
        return li_rtn;

    ts_ptr->_max_not = number_of_tests;

    return CREATE_SUCCESS;

}

int add_unit_test(c_testsheet_t* ts_ptr, const c_ut_ptr_t ut_ptr, const char* test_name){

    if ( ts_ptr == NULL )
        return NULL_TESTSHEET_PTR;

    if ( ts_ptr->_max_not <= 0 )
        return CREATE_TESTSHEET_FIRST;

    if ( ts_ptr->_curr_not == ts_ptr->_max_not )
        return TESTSHEET_IS_FULL;

    if ( strlen(test_name) > (UT_NAME_LENGTH - 1) )
        return TEST_NAME_TOO_LONG;

    *(ts_ptr->_ut_ptr_arr + ts_ptr->_curr_not) = ut_ptr;

    __ts_load_execution_data_struct(ts_ptr,
                                    test_name);

    ts_ptr->_curr_not++;

    return ADDUT_SUCCESS;

}

int delete_testsheet(c_testsheet_t* ts_ptr){

    void * del_ptr;
    int li_test_amount;

    if ( ts_ptr == NULL )
        return NULL_TESTSHEET_PTR;

    if ( ts_ptr->_max_not <= 0 )
        return CREATE_TESTSHEET_FIRST;



}
