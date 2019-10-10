/** primes.c
Reseni IJC-DU1, priklad a), 20.03.2019
Autor: Serhii Salatskyi, FIT
Prelozeno gcc 7.3.0
Program, ktery tiskne prvocislo na zvlastni radek v poradi vzestupnem
*/

#include "eratosthenes.h"

int main(){
	bit_array_create(field, 123000000L);
	eratosthenes(field);
	
	unsigned long prime[10];
        int count_of_primes = 0; 

	for(unsigned long index = bit_array_size(field); index > 0; index--){
                if(!bit_array_getbit(field, index)){
                        prime[count_of_primes++] = index;
                }
                if(count_of_primes == 10){
                        break;
                }
        }

        for(int i = count_of_primes-1; i >=0; i--)  printf("%lu\n", prime[i]);
	
	exit(0);
}

