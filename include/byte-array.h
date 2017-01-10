#ifndef BYTE_ARRAY
#define BYTE_ARRAY

#include <stdint.h>
#include <stdio.h>
#include "buffer.h"
#include "macros.h"

#define byte_array_t struct byte_array

// this is a class
struct byte_array {
  buffer_t *buffer;
  size_t length;

  // uint8
  uint8_t (*read_uint8)(byte_array_t *self, size_t offset);
  bool (*write_uint8)(byte_array_t *self, uint8_t value, size_t offset);
  // int8
  int8_t (*read_int8)(byte_array_t *self, size_t offset);
  bool (*write_int8)(byte_array_t *self, int8_t value, size_t offset);
  
  // uint16 LE
  uint16_t (*read_uint16_LE)(byte_array_t *self, size_t offset);
  bool (*write_uint16_LE)(byte_array_t *self, uint16_t value, size_t offset);
  // uint16 BE
  uint16_t (*read_uint16_BE)(byte_array_t *self, size_t offset);
  bool (*write_uint16_BE)(byte_array_t *self, uint16_t value, size_t offset);
  
  // int16 LE
  int16_t (*read_int16_LE)(byte_array_t *self, size_t offset);
  bool (*write_int16_LE)(byte_array_t *self, int16_t value, size_t offset);
  // int16 BE
  int16_t (*read_int16_BE)(byte_array_t *self, size_t offset);
  bool (*write_int16_BE)(byte_array_t *self, int16_t value, size_t offset);
  
  // uint32 LE
  uint32_t (*read_uint32_LE)(byte_array_t *self, size_t offset);
  bool (*write_uint32_LE)(byte_array_t *self, uint32_t value, size_t offset);
  // uint32 BE
  uint32_t (*read_uint32_BE)(byte_array_t *self, size_t offset);
  bool (*write_uint32_BE)(byte_array_t *self, uint32_t value, size_t offset);

  //int32 LE
  int32_t (*read_int32_LE)(byte_array_t *self, size_t offset);
  bool (*write_int32_LE)(byte_array_t *self, int32_t value, size_t offset);
  //in32 BE
  int32_t (*read_int32_BE)(byte_array_t *self, size_t offset);
  bool (*write_int32_BE)(byte_array_t *self, int32_t value, size_t offset);
};

byte_array_t *new_byte_array(size_t length);

#endif
