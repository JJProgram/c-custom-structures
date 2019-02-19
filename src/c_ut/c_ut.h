#ifndef C_UT_H_INCLUDED
#define C_UT_H_INCLUDED

#include <stdlib.h>
#include <string.h>

#include "c_ut_types/c_ut_types.h"
#include "c_ut_enums/c_ut_enums.h"

int     init_testsheet  (c_testsheet_t* ts_ptr);
int     create_testsheet(c_testsheet_t* ts_ptr, const int number_of_tests ); /// Allocate mem.
int     add_unit_test   (c_testsheet_t* ts_ptr, const c_ut_ptr_t ut_ptr, const char* test_name);
int     delete_testsheet(c_testsheet_t* ts_ptr); /// Free mem.

#endif // C_UT_H_INCLUDED
