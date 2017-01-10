#include <stdint.h>

#include "macros.h"
#include "minunit.h"
#include "buffer.h"
#include "byte-array.h"

#define byte_array_print(input) \
  for(int i=0; i<input->length; i++){ \
    printf("%s[%d]: 0X%X\n", #input, i, apply(input, read_uint8, i)); \
  } 

MU_TEST(test_size_of_buffer_type) {
  mu_check(size_of_buffer_type(INT) == sizeof(int32_t));
  mu_check(size_of_buffer_type(INT8) == sizeof(int8_t));
  mu_check(size_of_buffer_type(INT16) == sizeof(int16_t));
  mu_check(size_of_buffer_type(INT32) == sizeof(int32_t));
  mu_check(size_of_buffer_type(UINT) == sizeof(uint32_t));
  mu_check(size_of_buffer_type(UINT8) == sizeof(uint8_t));
  mu_check(size_of_buffer_type(UINT16) == sizeof(uint16_t));
  mu_check(size_of_buffer_type(UINT32) == sizeof(uint32_t));
}

MU_TEST(test_new_buffer){
  buffer_t *buf = new_buffer(4, UINT8);
  mu_check(buf->size == (sizeof(uint8_t) * 4));
  mu_check(buf->length == 4);
  mu_check(buf->type == UINT8);

  uint8_t *data = (uint8_t *) buf->data;
  for(int i=0; i<buf->length;i++){
    mu_check(data[i] == 0);
  }
}

MU_TEST(test_byte_array){
  byte_array_t *bAR = new_byte_array(10);
  mu_check(bAR->length == 10);
  mu_check(bAR->buffer->length == 10);

  int i;
  uint8_t unum8;;
  int8_t num8;
  // check that data is initalized to 0
  for(i=0; i<bAR->length; i++){
    unum8 = apply(bAR, read_uint8, i);
    mu_check(unum8 == 0);
  }

  // testing write_uint8 with valid offset
  bool check = apply(bAR, write_uint8, 2, 1);
  mu_check(check == true);
  // testing read_uint8 
  unum8 = apply(bAR, read_uint8, 1);
  mu_check(unum8 = 2);

  // testing write_uint8 with invalid offset
  check = apply(bAR, write_uint8, 2, 100);
  mu_check(check == false);

  // testing write_int8 with valid offset
  check = apply(bAR, write_int8, -120, 9);
  mu_check(check == true);
  // testing read_int8 
  num8 = apply(bAR, read_int8, 9);
  mu_check(num8 == -120);

   /*testing write_uint16_LE */
  check = apply(bAR, write_uint16_LE, 0xffee, 0);
  mu_check(check == true);

  unum8 = 0x7a;

  unum8 = apply(bAR, read_uint8, 0);
  mu_check(unum8 ==  0xee);
  unum8 = apply(bAR, read_uint8, 1);
  mu_check(unum8 ==  0xff);

  // testing read_uint16_LE  
  uint16_t uint16;
  uint16 = apply(bAR, read_uint16_LE, 0);
  mu_check(uint16 == 0xffee);

  uint16 = apply(bAR, read_int16_LE, 0);
  mu_check(uint16 == 0xffee);
  /*check = apply(bAR, write_int16_LE, 0xAFB7, 2);*/
  /*mu_check(check == true);*/

  check = apply(bAR, write_int16_LE, 0xaabb, 1);
  mu_check(check == true);
  unum8 = apply(bAR, read_uint8, 1);
  mu_check(unum8 ==  0xbb);
  unum8 = apply(bAR, read_uint8, 2);
  mu_check(unum8 ==  0xaa);
  
  puts("");
  byte_array_print(bAR);

  uint32_t test_uint32;
  apply(bAR, write_uint16_LE, 0xffaa, 2);
  apply(bAR, write_uint16_LE, 0xbbee, 0);
  test_uint32 = apply(bAR, read_uint32_LE, 0);
  mu_check(test_uint32 == 0xffaabbee);

  int32_t test_int32;
  apply(bAR, write_int16_LE, 0xffaa, 2);
  apply(bAR, write_int16_LE, 0xbbee, 0);
  test_int32 = apply(bAR, read_int32_LE, 0);
  mu_check(test_int32 == 0xffaabbee);

  check = apply(bAR, write_uint32_LE, 0xaabbccdd, 0);
  mu_check(check == true);
  test_uint32 = apply(bAR, read_uint32_LE, 0);
  mu_check(test_uint32 == 0xaabbccdd);

  check = apply(bAR, write_uint32_LE, 0xff0077aa, 0);
  mu_check(check == true);
  test_int32 = apply(bAR, read_uint32_LE, 0);
  mu_check(test_int32 == 0xff0077aa);
}

  

MU_TEST_SUITE(test_suite) {
  MU_RUN_TEST(test_size_of_buffer_type);
  MU_RUN_TEST(test_new_buffer);
  MU_RUN_TEST(test_byte_array);
}

int main(int argc, char *argv[]) {
  GC_INIT();
  MU_RUN_SUITE(test_suite);
  MU_REPORT();
  return 0;
}
