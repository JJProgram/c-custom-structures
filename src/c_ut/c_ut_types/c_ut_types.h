#ifndef C_UT_PTR_H_INCLUDED
#define C_UT_PTR_H_INCLUDED

#define UT_NAME_LENGTH 257

/// Puntero a una prueba unitaria
typedef int (*c_ut_ptr_t) (const void* package_in, void* package_out);

/// Estructura de parametros de ejecucion de una prueba
typedef struct  {

                    char    _test_name[UT_NAME_LENGTH];
                    /*
                        Mas atributos pendientes:
                        hora de inicio y fin de cada prueba, otros...
                    */

                } c_ut_xdata_t;

/// Estructura de hoja de pruebas

typedef struct  {

                    c_ut_ptr_t*     _ut_ptr_arr;
                    c_ut_xdata_t*   _ut_data_arr;
                    int             _max_not; // Max. number of tests
                    int             _curr_not; // Current. number of tests
                } c_testsheet_t;

#endif // C_UT_PTR_T_H_INCLUDED
