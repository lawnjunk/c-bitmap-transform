#include <gc.h>
#include <stdio.h>
#include "bitmap.h"
#include "bitmap_io.h"
#include "buffer.h"

int main(int argc, char **argv){
  //TODO: setup garbage collector
  GC_INIT();

  bitmap_t *bm = read_bitmap(argv[1]);

  call(bm, invert);

  bool check = write_bitmap(argv[2], bm);
  if(!check) 
    puts("something when wrong");
  puts("booya success!");
  /*printf("width: %u, height: %u", bm->width, bm->height);*/

  return 0;
}
