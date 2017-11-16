#include "../mini-assert/mini-assert.h"

struct component {
};

struct point {
};

struct point create_point(int x, int y) {
  // TODO: Fill the "point" and "component" data structures such that the following initialiser is valid.
  struct point created/* = { .x = { .value = { .integer = x }, .is_real = 0 }, .y = { .value = { .integer = y }, .is_real = 0 }, .next = 0 }*/;
  return created;
}

struct point create_pointf(float x, float y) {
  struct point created; // TODO: Implement analogous to create_point!
  return created;
}

void connect(struct point *lhs, struct point *rhs) {
  // TODO: Connect lhs and rhs.
}

void run_data_structures_exercise(void) {
  puts("Read/Write exercises");
  puts("------------------------------\n");

  struct point first = create_point(0, 0);
  struct point second = create_point(10, 10);
  connect(&first, &second);
  struct point third = create_pointf(30.25, 25.5);
  connect(&second, &third);

  // TODO: Uncomment these test cases once "component" and "point" are filled.
  /*struct point *point = &first;
   assert_equal_bool(point->x.is_real, 0);
   assert_equal_integer(point->x.value.integer, 0);
   assert_equal_bool(point->y.is_real, 0);
   assert_equal_integer(point->y.value.integer, 0);
   point = point->next;
   assert_equal_bool(point->x.is_real, 0);
   assert_equal_integer(point->x.value.integer, 10);
   assert_equal_bool(point->y.is_real, 0);
   assert_equal_integer(point->y.value.integer, 10);
   point = point->next;
   assert_equal_bool(point->x.is_real, 1);
   assert_equal_delta(point->x.value.real, 30.25);
   assert_equal_bool(point->y.is_real, 1);
   assert_equal_delta(point->y.value.real, 25.5);
   assert_equal_integer(0, (int) point->next);*/

  puts("\n");
}
