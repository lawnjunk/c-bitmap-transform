#include <gc.h>
#include <stdio.h>
#include "bitmap.h"
#include "bitmap_io.h"
#include "buffer.h"

int main(int argc, char **argv){
  //TODO: setup garbage collector
  GC_INIT();
  read_bitmap(argv[1]);
  return 0;
}
