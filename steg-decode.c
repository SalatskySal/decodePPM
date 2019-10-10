/** steg-decode.c
Reseni IJC-DU1, priklad b), 20.03.2019
Autor: Serhii Salatskyi, FIT
Prelozeno gcc 7.3.0
Program, ktery tiskne tajnou zpravu, dekodovanou z obrazku formatu .ppm
*/

#include "locale.h"
#include "ppm.h"
#include "eratosthenes.h"
#include "math.h"

int main(int argc, char *argv[]){
	ppm* image = ppm_read(argv[1]);
	const unsigned long size = 3*image->xsize*image->ysize;
        int bit_of_string = 0;
	bit_array_alloc(field, size);
	eratosthenes(field);

	for(unsigned long iter = 19L; iter < bit_array_size(field); iter++){
		if(!bit_array_getbit(field, iter)){
			bit_of_string++;
		}
	}

	int count = 0;
	bit_array_alloc(zprava, bit_of_string);
	for(unsigned long index = 19L; index < bit_array_size(field); index++){
                if(!bit_array_getbit(field, index)){
                        zprava[count/BIT_SIZE]|= (image->data[index]&1)<<(count%BIT_SIZE);
                        count++;
                }
        }
	printf("%s", (char*)&zprava[1]);
	
	bit_array_free(field);
	bit_array_free(zprava);
	ppm_free(image);
}
