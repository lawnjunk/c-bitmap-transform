#include <gc.h>
#include <stdio.h>
#include <stdint.h>

#ifndef BITMAP
#define BITMAP

#define bitmap_t struct bitmap

struct bitmap {
  char *type;  
  uint32_t size; 
  uint32_t pixels_offset;
  uint32_t width;
  uint32_t height;
  uint8_t *colors;
  uint8_t *pixels;

  // original buffer
  void *buffer;
};

struct bitmap *new_bitmap(uint8_t *buffer);

#endif
