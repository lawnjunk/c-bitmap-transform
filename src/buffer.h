#ifndef BUFFER
#define BUFFER
#include <stdio.h>
#include <gc.h>

typedef enum buffer_type {
    INT,  
    INT8, 
    INT16, 
    INT32, 
    UINT, 
    UINT8, 
    UINT16, 
    UINT32, 
    CHAR,
} buffer_type_t;

typedef struct buffer {
  void *data; 
  buffer_type_t type;
  size_t length; // lenth in number of type
  size_t size;   // size in bytes
} buffer_t;


// TODO: test
buffer_t *new_buffer(size_t bytes, buffer_type_t type);

// TODONE: tested
size_t size_of_buffer_type(buffer_type_t type); 

#endif
