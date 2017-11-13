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
    // The signed int is implicitly cased to an unsigned int.
    // This happens for many binary operations according to C type promotion rules.
    // The full set of these rules is very long, but most of them are intuitive.
    // Takeaway: You know these promotion rules exist and you can look them up when you encounter situations like this.
    puts("T1: Why is this line printed? Why is -1 > 248?\n");
  }

  int vint = -1;
  // printf(...) is a variadic function. It doesn't know the type of its arguments. It has to rely
  // on the format specification in the format string. Changing vint to an unsigned int doesn't
  // change the output. Only using %u in the format specifier will.
  printf("T2: What would this output be if we used %%u instead of %%d: %d? Explain why.\n\n", vint);

  double d;
  for (d = 10.0; d != 0.0; d -= 0.1) {
    if (d < -1.0) {
      // The problem here is imprecision with IEEE floating point types. d is never precisely
      // 0.0, because the floating point arithmetic is imprecise for decimal values.
      // Had we used d > 0.0 as a condition, then the line would not be printed.
      // Takeaway: IEEE floating point arithmetic is imprecise.
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
  // Takeaway: C casts are not always just bit reinterpretations. Upcasts will fill leading bits with '1' rather than '0'
  // if the casted value is negative, retaining the effective value.
}

/**
 * Q5: Cube Calculation
 */

float calculate_cube(float val){
  return val * val * val;
}

void run_get_cube(void){

  int input;
  printf("Give me an integer.\n");
  scanf("%d", &input);
  printf("The value is %.2f", calculate_cube(input));
}

/**
 * Q6: Bitwise operations
 */
int flip_msb(int value) {
  return value ^ 0x80000000;
}

int clear_lsb(int value) {
  return value & 0xFFFFFFFE;
}

int set_lsb_to_msb(int value) {
  if (value & 0x80000000) {
    return value | 0x00000001;
  }
  return value & 0xFFFFFFFE;
}

int switch_portions(int value) {
	  
  return ((unsigned int) value << 16) | ( (unsigned int) value >> 16 );
}

int count_number_of_set_bits(int value) {
  int count = 0;
  int i, mask;
  for (i = 0, mask = 1; i < 32; ++i, mask <<= 1) {
    if (value & mask) {
      ++count;
    }
  }
  return count;
}

/**
 * Q7: Coordinates exercise
 */
double distance_between_coordinates(int x1, int y1, int x2, int y2) {
  double x = x2 - x1;
  double y = y2 - y1;
  return sqrt(pow(x, 2.0) + pow(y, 2.0));
  //
  //     (x2,y2)
  //       /
  //      /
  //     /
  //    /
  // (x1,y1)
  //
}

/**
 * Q8: Time program
 */

void run_time_conversion(void) {

  int input;

  while(1)
  {
    printf("Please enter time in minutes:\n");
    fflush(stdout);
    scanf("%d", &input);

    if (input < 0){
      printf("Quiting...\n");
      break;
    }
    else{
      int numberOfMinutes = input % 60;
      int numberOfHours = input/60;
      printf("Total Minutes %d => %02d:%02d\n", input, numberOfHours, numberOfMinutes);

    }
  }
}

/**
 * Q9: Echo program
 */
void run_echo_exercise(void) {
  puts("\n");
  char line[1024];
  int index = 0;
  char c;
  do {
    if (index >= sizeof(line)) {
      puts("Input too long.");
      return;
    }
    c = getchar();
    line[index] = c;
    line[++index] = '\0';
    if (c == '\n') {
      printf("%s", line);
      index = 0;
    }
  } while (strcmp("exit\n", line));
}

/**
 * Q10: Recursion program
 */



void print_recursively(int val, int max){

  printf("%d\n", val);

  if (val != max){
    print_recursively(val + 1, max); 
  }
}

void run_recursive_print(){

  int val;
  printf("Give me an integer.\n");
  scanf("%d", &val);

  if (val < 0){
    printf("Invalid input. Must be greater than or equal to 0");
  }

  print_recursively(0, val);
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
  run_get_cube();
  run_coordinates_exercise();
  run_bitwise_exercises();
  run_time_conversion(); 
  run_echo_exercise();
  run_recursive_print();

  return 0;
}
