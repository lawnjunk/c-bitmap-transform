#include <stdint.h>
#include <string.h>

#include "macros.h"
#include "minunit.h"
#include "buffer.h"
#include "byte-array.h"

#define equal_strings(a, b) (strcmp(a, b) == 0)
#define equal_integer(a, b) ( a == b)

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

  mu_check(apply(bAR, write_uint16_BE, 0xffaa, 3));
  mu_check(apply(bAR, read_uint16_BE, 3) == 0xffaa);
  mu_check(apply(bAR, read_uint16_LE, 3) == 0xaaff);

  check = apply(bAR, write_int16_LE, 0xaabb, 1);
  mu_check(check == true);
  unum8 = apply(bAR, read_uint8, 1);
  mu_check(unum8 ==  0xbb);
  unum8 = apply(bAR, read_uint8, 2);
  mu_check(unum8 ==  0xaa);

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

  check = apply(bAR, write_uint32_BE, 0xff0077aa, 0);
  mu_check(check == true);
  test_int32 = apply(bAR, read_uint32_LE, 0);
  mu_check(test_int32 == 0xaa7700ff);
  test_int32 = apply(bAR, read_uint32_BE, 0);
  mu_check(equal_integer(test_int32, 0xff0077aa));
}

#define for_range(a, b) \
  for(int i=a; i<b; i++)

MU_TEST(test_write_string){
  byte_array_t *b_array = new_byte_array(25);
  apply(b_array, write_string, "hello world", 0);

  apply(b_array, write_string, "hello world", 0);
  char *result    = apply(b_array, read_string, 0, 5);
  char compare[5] = {'h', 'e', 'l', 'l', 'o' };
  mu_check(char_byte_compare(result, compare, 5));
  mu_check(equal_strings(result, "hello"));
  mu_check(equal_strings(call(b_array, to_string), "hello world"));

  // fill with 0's
  apply(b_array, fill_uint8, 0);
  for(int i=0; i<b_array->length; i++){
    mu_check(apply(b_array, read_uint8, i) == 0);
  }

  apply(b_array, fill_int8, -3);
  for(int i=0; i<b_array->length; i++){
    mu_check(apply(b_array, read_int8, i) == -3);
  }

  apply(b_array, fill_char, 'a');
  for(int i=0; i<b_array->length; i++){
    mu_check((char) apply(b_array, read_uint8, i) == 'a');
  }
}

MU_TEST_SUITE(test_suite) {
  MU_RUN_TEST(test_size_of_buffer_type);
  MU_RUN_TEST(test_new_buffer);
  MU_RUN_TEST(test_byte_array);
  MU_RUN_TEST(test_write_string);
}

int main(int argc, char *argv[]) {
  GC_INIT();
  MU_RUN_SUITE(test_suite);
  MU_REPORT();
  return 0;
}
