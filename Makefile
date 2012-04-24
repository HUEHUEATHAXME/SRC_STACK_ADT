all:
	gcc -Wall -o stacktest stacktest.c stack.c

clean:
	rm -f stacktest
	rm -f *~
	rm -f *.o