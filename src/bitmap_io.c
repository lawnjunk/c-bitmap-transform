#include "stdint.h"
#include "bitmap_io.h"
#include "byte_array.h"

bitmap_t *read_bitmap(char *path){
  // get file pointer
  FILE *infile = fopen(path, "r");
  // get file length
  fseek(infile, 0, SEEK_END); // jump to end of file
  long int length = ftell(infile); // get length
  fseek(infile, 0, SEEK_SET); // go back to begenning of file

  // allocate buffer
  byte_array_t *b_array = new_byte_array(length);

  // read bytes
  fread(b_array->buffer, length, 1, infile);

  // close infile
  fclose(infile);
  // make bitmap
  return new_bitmap(b_array);
  // return bitmap

}

int write_bitmap(bitmap_t *t);
