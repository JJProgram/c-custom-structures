#ifndef C_STRING_T_H_INCLUDED
#define C_STRING_T_H_INCLUDED

#include <stdlib.h>
#include <string.h>

typedef struct c_string_t{

    char *  _strptr;
    long    _length;
    long    _mem_size;

}c_string_t;

/// FUNCIONES  ///

/// Crear, cargar y liberar ///
void        c_string_create         ( c_string_t* ptr );    /// Crear
c_string_t* c_string_load           ( c_string_t* ptr, const char* str  );  /// Cargar
void        c_string_free           ( c_string_t* ptr );    /// Liberar/Vaciar

/// Obtener componentes de la estructura ///

char*       c_string_get_str        ( const c_string_t* ptr);   /// Obtener direccion de inicio de la cadena.
long        c_string_get_length     ( const c_string_t* ptr);   /// Obtener largo de la cadena de caracteres.
long        c_string_get_mem_size   ( const c_string_t* ptr);   /// Obtener memoria ocupada solo por la cadena.
long        c_string_get_unused_mem ( const c_string_t* ptr);   /// Obtener espacio no ocupado por la cadena.


c_string_t* c_string_append         ( c_string_t* ptrD, const c_string_t* ptrO  ); /// Agregar al final del c_string de Destino
c_string_t* c_string_append         ( c_string_t* ptrD, const char* str);
c_string_t* c_string_concat         ( const c_string_t* ptrD, const c_string_t* ptrO ); /// Concatena y produce un nuevo c_string


#endif // C_STRING_T_H_INCLUDED
