#include "minunit.h"
#include "buffer.h"
#include <stdint.h>

MU_TEST(wat) {
  mu_check(size_of_buffer_type(INT) == 4);
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(wat);
}

int main(int argc, char *argv[]) {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return 0;
}
