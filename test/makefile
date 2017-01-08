CFLAGS = -Wall
INCLUDE = -I ../include -I .
LIBS = -lgc


run: build 
	./tests
	rm ./tests
	
build: 
	clang ${CFLAGS} ${INCLUDE} test.c ../include/*.c ${LIBS} -o tests
