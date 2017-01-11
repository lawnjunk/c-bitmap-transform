#ifndef BITMAP
#define BITMAP

#include <gc.h>
#include <stdio.h>
#include <stdint.h>
#include "byte_array.h"

#define bitmap_t struct bitmap
struct bitmap {
  char *type;  
  uint32_t size; 
  uint32_t pixels_offset;
  uint32_t width;
  uint32_t height;
  byte_array_t *colors;
  byte_array_t *pixels;
  
  void (*invert)(bitmap_t *self);
  // original buffer
  byte_array_t *data;
};

struct bitmap *new_bitmap(byte_array_t *data);
#endif
