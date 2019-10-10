/** error.h
Reseni IJC-DU1, priklad a), 20.03.2019
Autor: Serhii Salatskyi, FIT
Prelozeno gcc 7.3.0
Hlavickovy soubor pro modul error.c
*/

#include "stdarg.h"
#include "stdlib.h"
#include "stdio.h"

#ifndef ERRORC_H
#define ERRORC_H

void warning_msg(const char *fmt, ...);
void error_exit(const char *fmt, ...);

#endif



