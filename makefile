CFLAGS = -Wall -g 
INCLUDE = -I model -I lib
LIBS = -lgc

all: 
	clang ${CFLAGS} ${INCLUDE} main.c lib/*.c model/*.c ${LIBS} -o build

E:
	clang -E ${CFLAGS}  main.c ${LIBS}
