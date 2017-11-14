#include "../mini-assert/mini-assert.h"

void change_sign(int *value) {
  // TODO: Write a program that changes the sign of the value passed.
}


void run_ptr_sign_exercise(void) {
  puts("Ptr Sign");
  puts("------------------------------\n");

  int val = -1;
  change_sign(&val);
  assert_equal_integer(val, 1);

  val = 1;
  change_sign(&val);
  assert_equal_integer(val, -1);

  val = 0;
  change_sign(&val);
  assert_equal_integer(val, 0);
}
