#ifndef BYTE_ARRAY
#define BYTE_ARRAY

#include <stdint.h>
#include <stdio.h>
#include "buffer.h"

#define byte_array_t struct byte_array

struct byte_array {
  buffer_t *buffer;
  size_t length;
  uint8_t (*read_uint8)(byte_array_t *self, size_t offset);
  int (*write_uint8)(byte_array_t *self, uint8_t value, size_t offset);
  int8_t (*read_int8)(byte_array_t *self, size_t offset);
  int (*write_int8)(byte_array_t *self, int8_t value, size_t offset);
  uint16_t (*read_uint16_LE)(byte_array_t *self, size_t offset);
  int (*write_uint16_LE)(byte_array_t *self, uint16_t value, size_t offset);
};

byte_array_t *new_byte_array(size_t length);

#endif
