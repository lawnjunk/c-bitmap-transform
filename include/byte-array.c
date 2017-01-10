#include <stdint.h>
#include "gc.h"
#include "byte-array.h"
#include "macros.h"

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
  bool name(byte_array_t *self, type value, size_t offset){ \
    if(offset > self->length) \
      return false; \
    type *nums = (type *) self->buffer->data; \
    nums[offset] = value; \
    return true; \
  }

make_write8(write_uint8, uint8_t);
make_write8(write_int8, int8_t);

#define make_read16(name, type) \
  type name(byte_array_t *self, size_t offset){ \
    uint8_t *nums = (uint8_t *) self->buffer->data; \
    type result; \
    result = (type) nums[offset+1]; \
    result = result << 8; \
    return result | nums[offset]; \
  }

make_read16(read_uint16_LE, uint16_t);
make_read16(read_int16_LE, int16_t);

#define write_int16(name, type) \
bool name(byte_array_t *self, type value, size_t offset){ \
  if(offset > self->length) \
    return false;  \
  uint8_t *nums = (uint8_t *) self->buffer->data; \
  nums[offset] = value & 0xff; \
  nums[offset+1] = value >> 8; \
  return true; \
}

write_int16(write_uint16_LE, uint16_t);
write_int16(write_int16_LE, int16_t);

#define read_int32(name, type) \
type name(byte_array_t *self, size_t offset){ \
  uint8_t *nums = (uint8_t *) self->buffer->data; \
  type result = nums[offset+3]; \
  result = (result << 8) | nums[offset + 2]; \
  result = (result << 8) | nums[offset + 1]; \
  return (result << 8) | nums[offset ]; \
}

read_int32(read_uint32_LE, uint32_t);
read_int32(read_int32_LE, int32_t);

#define make_write32LE(name, type) \
bool name(byte_array_t *self, type value, size_t offset){ \
  if(offset > self->length) \
    return false; \
  uint8_t *nums = (uint8_t *) self->buffer->data; \
  nums[offset] = value & 0xff; \
  nums[offset+1] = (value >> 8) & 0xff; \
  nums[offset+2] = (value >> 16) & 0xff; \
  nums[offset+3] = (value >> 24) & 0xff; \
  return true; \
}

make_write32LE(write_uint32_LE, uint32_t);
make_write32LE(write_int32_LE, int32_t);

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
  result->read_int16_LE = &read_int16_LE;
  result->write_int16_LE = &write_int16_LE;
  result->read_uint32_LE = &read_uint32_LE;
  result->read_int32_LE = &read_int32_LE;
  result->write_uint32_LE = &write_uint32_LE;
  result->write_int32_LE = &write_int32_LE;
  return result;
}
