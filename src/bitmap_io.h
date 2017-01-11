#ifndef BITMAP_IO
#define BITMAP_IO

#include <stdio.h>
#include "bitmap.h"

bitmap_t *read_bitmap(char *path);
bool write_bitmap(char* path, bitmap_t *bitmap);

#endif
