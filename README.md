


make


gcc -O2 -o dist/luhn.o -c luhn.c
gcc -O2 -o dist/main.o -c main.c 
gcc -O2 dist/luhn.o dist/main.o -o test
./test

Running unit tests 
passed

Running benchmark 20000000 times 
median: 1.954655 ns/op for len 176