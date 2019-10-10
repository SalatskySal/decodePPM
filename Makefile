CC=gcc
CFLAGS=-O2 -std=c11 -Wall -pedantic
LDFLAGS=-DUSE_INLINE
SOURCE_PRIMES=primes.c library.h library.c eratosthenes.h eratosthenes.c error.h error.c
SOURCE_DECODE=steg-decode.c library.h library.c eratosthenes.h eratosthenes.c ppm.h ppm.c error.h error.c
EXECUTABLE=primes primes-i steg-decode

all: $(EXECUTABLE)

steg-decode: $(SOURCE_DECODE)
	$(CC) $(CFLAGS) $(SOURCE_DECODE) -lm -o steg-decode

primes-i: $(SOURCE_PRIMES)
	$(CC) -DUSE_INLINE $(CFLAGS) $(SOURCE_PRIMES) -lm -o $@

primes: $(SOURCE_PRIMES)
	$(CC) $(CFLAGS) $(SOURCE_PRIMES) -lm -o $@

run: primes primes-i
	ulimit -s 16000
	time ./primes
	time ./primes-i





