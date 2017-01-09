#include <stdint.h>
#include "gc.h"
#include "byte-array.h"

// make_read8 creates a functions for reading 8bit
// signed and unsinged ints, at a size_t offset
// return type (type)
#define make_read8(name, type) \
  type name(byte_array_t *self, size_t offset){ \
    type *nums = (type *) self->buffer->data; \
    return nums[offset]; \
  }

make_read8(read_uint8, uint8_t);
make_read8(read_int8, int8_t);

// make_write8 creates functions for writing a signed
// or unsigned 8bit int, at a size_t offse
// return type int
// return -1 on fail
// return 0 on success
#define make_write8(name, type) \
  int name(byte_array_t *self, type value, size_t offset){ \
    if(offset > self->length) \
      return -1; \
    type *nums = (type *) self->buffer->data; \
    nums[offset] = value; \
    return 0; \
  }

make_write8(write_uint8, uint8_t);
make_write8(write_int8, int8_t);

int write_uint16_LE(byte_array_t *self, uint16_t value, size_t offset){
  if(offset > self->length)
    return -1; 
  uint8_t *nums = (uint8_t *) self->buffer->data;
  nums[offset] = value & 0x00ff;
  nums[offset+1] = value >> 8;

  return 0;
}

uint16_t read_uint16_LE(byte_array_t *self, size_t offset){
  uint8_t *nums = (uint8_t *) self->buffer->data;
  uint16_t result;
  result = (uint16_t) nums[offset+1];
  result = result << 8;
  return result | nums[offset];
}

byte_array_t *new_byte_array(size_t length){
  byte_array_t *result = GC_MALLOC(sizeof(byte_array_t));
  result->buffer = new_buffer(length, UINT8);
  result->length = length;
  result->read_uint8 = &read_uint8;
  result->read_int8 = &read_int8;
  result->write_uint8 = &write_uint8;
  result->write_int8 = &write_int8;
  result->read_uint16_LE = &read_uint16_LE;
  result->write_uint16_LE = &write_uint16_LE;
  return result;
}
