#include <gc.h>
#include <stdio.h>
#include "bitmap.h"
#include "bitmap_io.h"
#include "buffer.h"

int main(int argc, char **argv){
  //TODO: setup garbage collector

  read_bitmap(argv[1]);

  /*void *lul = GC_MALLOC(sizeof(bitmap_t));*/
  printf("sdlfkjsdlfk \
      lsfdkjdfj\
      lskdfldfkj\
      sldkfjdf");

  printf("%ld", size_of_buffer_type(INT));
  //TODO: parse args
  //TODO: read file
  //TODO: transform 
  //TODO: writefile
  return 0;
}
