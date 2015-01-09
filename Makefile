qbrsa: qbrsa.c qbrsa.h
	gcc -Wall -Wextra -g -o qbrsa qbrsa.c -lgmp
	./qbrsa msg2.txt
