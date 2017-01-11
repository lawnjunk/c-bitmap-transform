#include <gc.h>
#include "bitmap.h"
#include "macros.h"

bitmap_t *new_bitmap(byte_array_t *data){

  bitmap_t *result = GC_MALLOC(sizeof(bitmap_t));
  printf("data.length %lu", data->length);
  byte_array_print(data);

  return result;
  /*char *lul = (char *) buffer;*/
  /*int i;*/
  /*for(i=0; i<100; i++){*/
    /*printf("%c", lul[i]);*/
  /*}*/
  /*return result;*/
}
