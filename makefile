CFLAGS = -Wall -g 
INCLUDE = -I src
SOURCE = src/*.c
LIBS = -lgc 

all: 
	clang ${CFLAGS} ${INCLUDE} main.c ${SOURCE} ${LIBS} -o build

E:
	clang -E ${CFLAGS}  main.c ${LIBS}

t: 
	make -C test
