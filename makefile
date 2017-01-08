CFLAGS = -Wall -g 
INCLUDE = -I include
LIBS = -lgc

all: 
	clang ${CFLAGS} ${INCLUDE} main.c include/*.c ${LIBS} -o build

E:
	clang -E ${CFLAGS}  main.c ${LIBS}

t: 
	make -C test
