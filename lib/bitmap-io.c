#include "stdint.h"
#include "bitmap-io.h"

bitmap_t *read_bitmap(char *path){
  // get file pointer
  FILE *infile = fopen(path, "r");
  // get file length
  fseek(infile, 0, SEEK_END); // jump to end of file
  long int length = ftell(infile); // get length
  fseek(infile, 0, SEEK_SET); // go back to begenning of file

  // allocate buffer
  uint8_t *buffer = (uint8_t *) GC_MALLOC(length);

  // read bytes
  fread(buffer, length, 1, infile);

  // close infile
  fclose(infile);
  // make bitmap
  return new_bitmap((uint8_t *) buffer);
  // return bitmap

}

int write_bitmap(bitmap_t *t);
