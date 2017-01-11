#include <gc.h>
#include <stdint.h>
#include "bitmap.h"
#include "macros.h"
#include "byte_array.h"

void invert(bitmap_t *self){
  byte_array_t *colors = self->colors;
  for(int i=0; i<colors->length; i++){
    uint8_t num = apply(colors, read_uint8, i);
    num = 255 - num;
    apply(colors, write_uint8, num, i);
  }
}

bitmap_t *new_bitmap(byte_array_t *data){
  bitmap_t *result = GC_MALLOC(sizeof(bitmap_t));
  result->data = data;
  result->type = apply(data, read_string, 0, 2);
  result->pixels_offset = apply(data, read_uint32_LE, 10);
  result->width = apply(data, read_uint32_LE, 18);
  result->height = apply(data, read_uint32_LE, 22);
  result->colors = apply(data, slice, 54, result->pixels_offset);
  result->pixels = apply(data, slice, result->pixels_offset, data->length);

  add_method(result, invert);
  return result;
}
