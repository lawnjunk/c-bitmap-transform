#include <gc.h>
#include "bitmap.h"
#include "macros.h"

bitmap_t *new_bitmap(byte_array_t *data){
  bitmap_t *result = GC_MALLOC(sizeof(bitmap_t));
  result->data = data;
  result->type = apply(data, read_string, 0, 2);
  result->pixels_offset = apply(data, read_uint32_LE, 10);
  result->width = apply(data, read_uint32_LE, 18);
  result->height = apply(data, read_uint32_LE, 22);

  printf("width:%u height: %u\n", result->width, result->height);
  return result;
}
