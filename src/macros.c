#include "macros.h"

bool char_byte_compare(char *a, char *b, int length){
  bool success = true;
  for(int i=0; i<length;i++){
    if(a[i] != b[i]) success=false;
  }
  return success;
}
