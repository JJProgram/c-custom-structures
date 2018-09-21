#include "c_string_t.h"

/**
    Descripcion:  Inicializar la estructura para su uso.
    Parametros:   1
        -   c_string_t* ptr -> Direccion de la estructura string.
    Retorno:
        -   void
*/
void c_string_create( c_string_t* ptr ){

    ptr->_strptr    = NULL;
    ptr->_length    = -1;
    ptr->_mem_size  = 0;

}

/**
    Descripcion:  Liberar el espacio consumido para la cadena, dejando la estructura en el estado inicial.
    Parametros:   1
        -   c_string_t* ptr ->  Direccion de la estructura string.
    Retorno:
        -   void
*/
void c_string_free( c_string_t* ptr ){

    if ( ptr->_strptr != NULL )
        free(ptr->_strptr);
    ptr->_strptr    = NULL;
    ptr->_length    = -1;
    ptr->_mem_size  = 0;

}

/**
    Descripcion:  Carga la estructura con el string suministrado en el segundo parametro. Es precondicion
                    haber utilizado c_string_create antes.
    Parametros:   1
        -   c_string_t* ptr ->  Direccion de la estructura string.
        -   const char* str ->  Direccion de inicio de la cadena a guardar en la estructura.
    Retorno:
        -   c_string_t*     ->  Direccion de la misma estructura que se paso por parametro.
    Error:
        -   NULL            -> Si ptr o str o ambos son NULL,
*/
c_string_t* c_string_load( c_string_t* ptr, const char* str  ){

    long   str_memsize;
    char*  aux_pointer;

    if ( !ptr || !str )
        return NULL;

    str_memsize = strlen(str) + 1;

    if ( str_memsize > ptr->_mem_size ){
        // Si Necesito mas memoria
        aux_pointer = (char* ) malloc( sizeof(char) * (str_memsize+1) );

        if ( !aux_pointer )
            return NULL;

        free(ptr->_strptr);

        ptr->_strptr   = aux_pointer;
        ptr->_mem_size = str_memsize;

    }

    strcpy(ptr->_strptr, str);
    ptr->_length = str_memsize - 1;

    return ptr;

}

/**
    Descripcion: Permite obtener la direccion del primer elemento de la cadena de caracteres.
    Parametros:   1
        -   c_string_t* ptr ->  Direccion de la estructura string.
    Retorno:
        -   char*           ->  Direccion de inicio de la cadena de caracteres.
*/
char* c_string_get_str( const c_string_t* ptr){

    return ptr->_strptr;

}

/**
    Descripcion: Permite obtener la cantidad de caracteres de la cadena, sin incluir el caracter de fin de
                    fin de cadena (\0). No se debe confundir el largo con el tamaño en memoria.
    Parametros:   1
        -   c_string_t* ptr ->  Direccion de la estructura string.
    Retorno:
        -   long            ->  Cantidad de caracteres que componenen la cadena sin incluir '\0'.
*/
long c_string_get_length( const c_string_t* ptr){

    return ptr->_length;

}

/**
    Descripcion: Permite obtener la cantidad de caracteres que ocupa en memoria la cadena.
    Parametros:   1
        -   c_string_t* ptr ->  Direccion de la estructura string.
    Retorno:
        -   long            ->  Cantidad de caracteres que ocupa la cadena en memoria
*/
long c_string_get_mem_size( const c_string_t* ptr){

    return ptr->_mem_size;

}

/**
    Descripcion:  Permite obtener la cantidad de lugares sin ocupar de la memoria requerida para
                    la cadena de caracteres.
    Parametros:   1
        -   c_string_t* ptr ->  Direccion de la estructura de string.
    Retorno:
        -   long            ->  Cantidad de lugares sin ocupar de la memoria requerida
*/
long c_string_get_unused_mem( const c_string_t* ptr){

    return ptr->_strptr==NULL?0:ptr->_mem_size - (ptr->_length + 1);

}

/**
    Descripcion:  Adiciona la cadena de caracteres de la estructura del segundo parametro
                    al final de la cadena de la estructura del primer parametro.
    Parametros:   1
        -   c_string_t* ptrDe       ->  Direccion de la estructura de string de Destino.
        -   const c_string_t* ptrOr ->  Direccion de la estructura de string de Origen.
    Retorno:
        -   c_string_t*     ->  Direccion de la estructura del primer parametro.
    Error:
        -   NULL            ->  Si ptrDe, ptrOr o sus strptr son NULL.
*/
c_string_t* c_string_append( c_string_t* ptrDe, const c_string_t* ptrOr  ){

    long    str_memsize;
    char    *aux_pointer;

    if ( (!ptrDe && ptrDe->_strptr == NULL )|| (!ptrOr && ptrOr->_strptr == NULL ) )
        return NULL;

    if ( ptrOr->_length > 0 ){

        str_memsize = ptrOr->_length + ptrDe->_length + 1;

        if ( str_memsize > ptrDe->_mem_size ){
            // Necesito mas memoria
            aux_pointer = (char* ) malloc( sizeof(char) * (ptrDe->_length + ptrOr->_length + 1) );

            if ( !aux_pointer )
                return NULL;

            strcpy(aux_pointer, ptrDe->_strptr);
            free(ptrDe->_strptr);
            ptrDe->_strptr   = aux_pointer;
            ptrDe->_mem_size = str_memsize;

        }

        strcat(ptrDe->_strptr, ptrOr->_strptr);
        ptrDe->_length += ptrOr->_length;

    }

    return ptrDe;

}

/**
    Descripcion:  Genera una estructura con la concatenacion de las cadenas de caracteres
                    de la primera estructura y luego la segunda estructura. Usar con cuidado
                    ya que retorna un puntero a una estructura string generada dinamicamente.
                    Es responsabilidad del usuario llamar a c_string_free y luego hacer un free
                    de la estructura propiamente dicha.
    Parametros:   1
        -   const c_string_t* ptrOr1       ->  Direccion de la estructura de string de Destino.
        -   const c_string_t* ptrOr2 ->  Direccion de la estructura de string de Origen.
    Retorno:
        -   c_string_t*     ->  Direccion de la estructura del primer parametro.
    Error:
        -   NULL            ->  Si ptrOr1, ptrOr2 o sus strptr son NULL.
*/
c_string_t* c_string_concat(const c_string_t* ptrOr1, const c_string_t* ptrOr2  ){

    long str_memsize;
    c_string_t* c_str;

    if ( (!ptrOr1 && ptrOr1->_strptr == NULL )|| (!ptrOr2 && ptrOr2->_strptr == NULL ) )
        return NULL;

    c_str = (c_string_t*) malloc( sizeof(c_string_t) );

    if (!c_str)
        return NULL;

    str_memsize      = ptrOr1->_length + ptrOr2->_length +1;
    c_str->_strptr   = malloc( sizeof(char) * str_memsize );
    c_str->_length   = str_memsize - 1;
    c_str->_mem_size = str_memsize;

    return c_str;
}


