#include <gc.h>
#include <stdio.h>
#include "bitmap.h"
#include "bitmap-io.h"
#include "buffer.h"

int main(int argc, char **argv){
  //TODO: setup garbage collector

  void *lul = GC_MALLOC(sizeof(bitmap_t));
  new_bitmap(lul);
/*bitmap_t *bm = read_bitmap("./main.c");*/

  printf("%ld", size_of_buffer_type(INT));
  //TODO: parse args
  //TODO: read file
  //TODO: transform 
  //TODO: writefile
  return 0;
}
