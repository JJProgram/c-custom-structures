#ifndef C_UT_ENUMS_H_INCLUDED
#define C_UT_ENUMS_H_INCLUDED

enum shared_rtns_e{

    NULL_TESTSHEET_PTR      =   -4,
    INIT_TESTSHEET_FIRST    =   -5,
    CREATE_TESTSHEET_FIRST  =   -6

};

enum init_rtns_e{

    INIT_SUCCESS            =   0

};

enum create_rtns_e{

    CREATE_SUCCESS          =   0,
    MEM_ERROR_UT_PRM        =   -1,
    MEM_ERROR_UT_PTR        =   -2,
    INVALID_NUMBER_OF_TESTS =   -3

};

enum addut_rtns_e{

    ADDUT_SUCCESS           =   0,
    TESTSHEET_IS_FULL       =   -1,
    TEST_NAME_TOO_LONG      =   -2,

};


#endif // C_UT_ENUMS_H_INCLUDED
