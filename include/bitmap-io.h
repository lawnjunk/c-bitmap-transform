#ifndef BITMAP_IO
#define BITMAP_IO

#include <stdio.h>
#include "bitmap.h"

bitmap_t *read_bitmap(char *path);
int write_bitmap(bitmap_t *t);

#endif
