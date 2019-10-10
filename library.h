/** library.h
Reseni IJC-DU1, priklad a), 20.03.2019
Autor: Serhii Salatskyi, FIT
Prelozeno gcc 7.3.0
Hlavickovy soubor pro definice bitoveho pole a prace s nim
*/

#include <stdlib.h>
#include "error.h"
#include "limits.h"
#include <stdio.h>
#include "assert.h"

#ifndef LIBRARY_H
#define LIBRARY_H

typedef unsigned long bit_array_t;

#define BIT_SIZE (8*sizeof(unsigned long))

#define LIMIT_SIZE 1000000000L

#define bit_array_create(name, size)\
    bit_array_t name[((size-1)/BIT_SIZE) + 2] = { 0 };\
    static_assert(size<LIMIT_SIZE, "Predana hodnota je vetsi nez maximalni velikost pole");\
    name[0] = size;\

#define bit_array_alloc(name, size) \
    bit_array_t* name;\
    assert(size<LIMIT_SIZE);\
    \
    name = (bit_array_t*)calloc(((size-1)/BIT_SIZE) + 2, sizeof(bit_array_t));\
    assert(name != NULL);\
    \
    name[0] = size;\
    for(unsigned long i = 1L; i < ((size-1)/BIT_SIZE) + 2; i++) name[i] = 0L;

#ifdef DUSE_INLINE

inline unsigned long bit_array_size(bit_array_t* name){
    return name[0];
}

inline inline void bit_array_free(bit_array_t* name){
    free(name);
    
}

inline inline void bit_array_setbit(bit_array_t* name, unsigned long index, int value){
        if(index > bit_array_size(name)){
                error_exit("bit_array_getbit: Index %lu mimo rozsah 0..%lu", (unsigned long)index, (unsigned long)bit_array_size(name));
        }
        if(value)   (name[(index/BIT_SIZE)+1] |= (1UL << (index%BIT_SIZE)));
}

inline inline bit_array_t bit_array_getbit(bit_array_t* name, unsigned long index){
        if(index > bit_array_size(name)){
                error_exit("bit_array_getbit: Index %lu mimo rozsah 0..%lu", (unsigned long)index, (unsigned long)bit_array_size(name));
        }
        if(name[(index/BIT_SIZE)+1] & (1UL << (index%BIT_SIZE))) return 1UL;\
        else return 0UL;\
}

#else

#define bit_array_size(name)	(name[0])

#define bit_array_free(name)\
    free(name)

#define bit_array_setbit(name, index, value)\
	(index>bit_array_size(name))? (error_exit("Index %d v setbit mimo rozsah 0...%d", index, bit_array_size(name)), 0):(name[(index/BIT_SIZE)+1] |= 1UL << (index%BIT_SIZE));

#define bit_array_getbit(name, index)\
	((index>bit_array_size(name))?(error_exit("Index %lu v getbit mimo rozsah 0...%d", (unsigned long)index, bit_array_size(name)), 0):(name[(index/BIT_SIZE)+1] & (1UL << (index%BIT_SIZE))))

#endif

#endif



