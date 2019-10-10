/** library.c
Reseni IJC-DU1, priklad a), 20.03.2019
Autor: Serhii Salatskyi, FIT
Prelozeno gcc 7.3.0
Modul pro library.h s externími definicemi inline funkcí
*/

#include "library.h"

#ifdef DUSE_INLINE
extern unsigned long bit_array_size(bit_array_t* name);
extern void bit_array_free(bit_array_t* name);
extern void bit_array_setbit(bit_array_t* name, unsigned long index, int value);
extern bit_array_t bit_array_getbit(bit_array_t* name, unsigned long index);
#endif
