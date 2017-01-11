#include <gc.h>
#include <stdio.h>
#include "bitmap.h"
#include "bitmap_io.h"
#include "buffer.h"

int main(int argc, char **argv){
  //TODO: setup garbage collector
  GC_INIT();
  /*read_bitmap(argv[1]);*/

  uint8_t *lul = GC_MALLOC(20);
  uint8_t *wat = lul + 5;
  for(int i=0;i<20;i++){
    lul[i] = 0;
    printf("%u", lul[i]);
  }

  printf("wat");
  for(int i=0;i<10;i++){
    printf("%u", wat[i]);
  }

  return 0;
}
