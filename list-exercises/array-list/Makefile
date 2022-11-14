CFLAGS=-g -std=c99
LDFLAGS=-L .

get: main.o ArrayList.o 
	gcc -o $@.exe main.o ArrayList.o ${LDFLAGS} -lget

initialize: main.o ArrayList.o
	gcc -o $@.exe main.o ArrayList.o ${LDFLAGS} -linitialize

set: main.o ArrayList.o
	gcc -o $@.exe main.o ArrayList.o ${LDFLAGS} -lset

truncate: main.o ArrayList.o
	gcc -o $@.exe main.o ArrayList.o ${LDFLAGS} -ltruncate

compact: main.o ArrayList.o
	gcc -o $@.exe main.o ArrayList.o

clean:
	rm -f get initialize.exe set.exe truncate.exe compact.exe *.o
