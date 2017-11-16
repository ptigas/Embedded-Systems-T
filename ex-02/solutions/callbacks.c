#include <stdio.h>

typedef void (*callbackt)(void);
#define CALLBACK_STORAGE_SIZE 10
static callbackt CALLBACKS[CALLBACK_STORAGE_SIZE];

void event_occurred(void) {
  int i;
  for (i = 0; i < CALLBACK_STORAGE_SIZE; ++i) {
    const callbackt cb = CALLBACKS[i];
    if (cb) {
      cb();
    }
  }
}

void add_callback(callbackt callback) {
  int i;
  for (i = 0; i < CALLBACK_STORAGE_SIZE; ++i) {
    if (!CALLBACKS[i]) {
      CALLBACKS[i] = callback;
      break;
    }
  }
}

void remove_callback(callbackt callback) {
  int i;
  for (i = 0; i < CALLBACK_STORAGE_SIZE; ++i) {
    if (callback == CALLBACKS[i]) {
      CALLBACKS[i] = 0;
    }
  }
}

void first(void) {
  puts("first");
}

void second(void) {
  puts("second");
}

void run_callbacks_exercise(void) {
  puts("Callback exercises");
  puts("------------------------------\n");
  add_callback(first);
  add_callback(second);
  event_occurred();
  remove_callback(second);
  event_occurred();
  puts("\n");
}
