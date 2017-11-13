#include "../mini-assert/mini-assert.h"
#include <math.h>


/**
 * Q3: Common type issues
 */
void run_types_exercise(void) {
  puts("Types exercises");
  puts("------------------------------\n");
  unsigned int uint = 248;
  signed int sint = -1;
  if (sint > uint) {
    puts("T1: Why is this line printed? Why is -1 > 248?\n");
  }

  int vint = -1;
  printf("T2: What would this output be if we used %%u instead of %%d: %d? Explain why.\n\n", vint);

  double d;
  for (d = 10.0; d != 0.0; d -= 0.1) {
    if (d < -1.0) {
      puts("T3: This loop should have terminated at 0.0. Why is this line still printed?\n");
      break;
    }
  }

  int initial = 0xFF;
  char down_cast = (char) initial;
  int up_cast = (int) down_cast;
  printf("T4: Why is initial != up_cast (%d != %d)? What's the difference between a signed integer downcast vs. upcast?\n", initial, up_cast);

  initial = 0x7F;
  down_cast = (char) initial;
  up_cast = (int) down_cast;
  printf("T4: initial == up_cast (%d != %d)? What is the difference to the previous situation?\n\n\n", initial, up_cast);
}


/**
 * Q4: Bitwise operations
 */
int flip_msb(int value) {
  // TODO: Implement
  return value;
}

int clear_lsb(int value) {
  // TODO: Implement
  return value;
}

int set_lsb_to_msb(int value) {
  // TODO: Implement
  return value;
}

int switch_portions(int value) {
  // TODO: Transform 0xABCD1234 to 0x1234ABCD
  return value;
}

int count_number_of_set_bits(int value) {
  // TODO: Count the number of bits set in the provided value.
  return 0;
}


/**
 * Q5: Coordinates exercise
 */
double distance_between_coordinates(int x1, int y1, int x2, int y2) {
  // TODO: Implement: Calculate the distance between the two points
  //
  //     (x2,y2)
  //       /
  //      /
  //     /
  //    /
  // (x1,y1)
  //
  return 0.0;
}


/**
 * Q6: Echo program
 */
void run_echo_exercise(void) {
  // TODO: Write a program which echoes every line of code entered, until an "exit" line is received.
}



void run_coordinates_exercise(void) {
  puts("Coordinates exercise tests");
  puts("------------------------------\n");
  assert_equal_delta(distance_between_coordinates(0, 0, 0, 0), 0.0);
  assert_equal_delta(distance_between_coordinates(0, 10, 20, 20), 22.36);
  assert_equal_delta(distance_between_coordinates(-10, -10, 20, 20), 42.42);
  assert_equal_delta(distance_between_coordinates(20, 20, -10, -10), 42.42);
  assert_equal_delta(distance_between_coordinates(50, 0, 80, 0), 30.0);
  puts("\n");
}

void run_bitwise_exercises(void) {
  puts("Bitwise exercise tests");
  puts("------------------------------\n");
  assert_equal_hex(flip_msb(0x80000000), 0x00000000);
  assert_equal_hex(flip_msb(0x00000000), 0x80000000);
  assert_equal_hex(flip_msb(0x01234567), 0x81234567);
  assert_equal_hex(flip_msb(0x81234567), 0x01234567);
  assert_equal_hex(clear_lsb(0x00000001), 0x00000000);
  assert_equal_hex(clear_lsb(0x81234567), 0x81234566);
  assert_equal_hex(set_lsb_to_msb(0x80000000), 0x80000001);
  assert_equal_hex(set_lsb_to_msb(0x00000001), 0x00000000);
  assert_equal_hex(set_lsb_to_msb(0x01234561), 0x01234560);
  assert_equal_hex(switch_portions(0xABCD1234), 0x1234ABCD);
  assert_equal_hex(switch_portions(0x00000000), 0x00000000);
  assert_equal_hex(switch_portions(0x00010000), 0x00000001);
  assert_equal_hex(count_number_of_set_bits(0xABCD0123), 14);
  assert_equal_hex(count_number_of_set_bits(0x00000000), 0);
  assert_equal_hex(count_number_of_set_bits(0x00000003), 2);
}

int main(void) {
  run_types_exercise();
  run_coordinates_exercise();
  run_bitwise_exercises();
  run_echo_exercise();

  return 0;
}
