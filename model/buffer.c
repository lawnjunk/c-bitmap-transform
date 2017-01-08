#include <stdint.h>
#include "buffer.h"

// returns -1 on failure
size_t size_of_buffer_type(buffer_type_t type){
  switch(type){
    case(INT):
      return sizeof(int32_t);
    case(INT8):
      return sizeof(int8_t);
    case(INT16):
      return sizeof(int16_t);
    case(INT32):
      return sizeof(int32_t);
    case(UINT):
      return sizeof(uint32_t);
    case(UINT8):
      return sizeof(uint8_t);
    case(UINT16):
      return sizeof(uint16_t);
    case(UINT32):
      return sizeof(uint32_t);
    default:
      return -1;
  }
}

buffer_t *new_buffer(size_t size, buffer_type_t type){
  buffer_t *result = GC_MALLOC(sizeof(buffer_t));
  return result;
} 
