/** eratosthenes.c
Reseni IJC-DU1, priklad a), 20.03.2019
Autor: Serhii Salatskyi, FIT
Prelozeno gcc 7.3.0
Modul pro nastaveni bitoveho pole pomoci algoritmu Eratostenoveho sita
*/

#include "library.h"
#include "eratosthenes.h"
#include "math.h"

void eratosthenes(bit_array_t* field){
	bit_array_setbit(field, 0, 1);
        bit_array_setbit(field, 1, 1);
        for(unsigned long iter = 2L; iter <= sqrt(bit_array_size(field)); iter++){
                if(!bit_array_getbit(field, iter)){
                        for(unsigned long koef = iter*iter; koef <= bit_array_size(field); koef+=iter){
                                bit_array_setbit(field, koef, 1);
                        }

                }
        }
}

