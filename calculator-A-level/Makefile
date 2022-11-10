CFLAGS=-g
CC=gcc

calc.exe: main.o getop.o stack.o getch.o
	gcc -o calc.exe main.o getop.o stack.o getch.o -lm

main.o: main.c calc.h

getop.o: getop.c calc.h

stack.o: stack.c calc.h

getch.o: getch.c

clean:
	rm -f *.o
	rm -f calc.exe
