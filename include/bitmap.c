#include "bitmap.h"

bitmap_t *new_bitmap(uint8_t *buffer){
  bitmap_t* result = GC_MALLOC(sizeof(bitmap_t));

  /*char *lul = (char *) buffer;*/
  /*int i;*/
  /*for(i=0; i<100; i++){*/
    /*printf("%c", lul[i]);*/
  /*}*/
  return result;
}
