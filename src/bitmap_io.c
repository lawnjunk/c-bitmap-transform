#include "stdint.h"
#include "bitmap_io.h"
#include "byte_array.h"

bitmap_t *read_bitmap(char *path){
  // get file pointer
  FILE *infile = fopen(path, "r");
  byte_array_t *data = new_byte_array_from_file(infile);
  fclose(infile);

  return new_bitmap(data);

}

int write_bitmap(bitmap_t *t);
