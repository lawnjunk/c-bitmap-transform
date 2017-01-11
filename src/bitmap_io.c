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

bool write_bitmap(char *path, bitmap_t *bitmap){
  FILE *outfile = fopen(path, "w");
  if(outfile == NULL){
    fprintf(stderr, "Error opening file\n");
    return false;
  }

  char *buf = (char *) bitmap->data->buffer;
  size_t length = bitmap->data->length;
  fwrite(buf, 1, length, outfile);
  return true;
}
