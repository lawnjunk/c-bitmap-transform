#ifndef BITMAP
#define BITMAP
#define bitmap_t struct bitmap

#include <gc.h>
#include <stdio.h>
#include <stdint.h>

#include "byte_array.h"

struct bitmap {
  char *type;  
  uint32_t size; 
  uint32_t pixels_offset;
  uint32_t width;
  uint32_t height;
  byte_array_t *colors;
  byte_array_t *pixels;
  
  // original buffer
  byte_array_t *data;
};

struct bitmap *new_bitmap(byte_array_t *data);
#endif
