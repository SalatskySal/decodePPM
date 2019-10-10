/** ppm.h
Reseni IJC-DU1, priklad b), 20.03.2019
Autor: Serhii Salatskyi, FIT
Prelozeno gcc 7.3.0
Hlavickovy soubor pro modul ppm.c
*/

#include <stdio.h>
#include <stdlib.h>

#ifndef PPM_H
#define PPM_H

typedef struct ppm{
	unsigned xsize;
	unsigned ysize;
	unsigned char* data;
}ppm;

struct ppm* ppm_read(const char* filename);
void ppm_free(ppm* p);

#endif
