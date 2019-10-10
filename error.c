/** error.c
Reseni IJC-DU1, priklad a), 20.03.2019
Autor: Serhii Salatskyi, FIT
Prelozeno gcc 7.3.0
Modul pro vytiskneni chyboveho hlaseni 
*/

#include "error.h"

extern void warning_msg(const char* fmt, ...){
    va_list ap;

    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);
}

extern void error_exit(const char *fmt, ...){
    va_list ap;

    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);

    exit(1);
}
