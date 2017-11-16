#include <stdio.h>

int *reserve_memory() {
  return (int *) malloc(20 * sizeof(int));
}

void initialise_memory(int *data) {
  int i;
  for (i = 0; i < 20;++i) {
    data[i] = 0;
  }
}

void manipulate_data(int *data) {
  data[0] = 1;
  data[1] = 1;
  int i;
  for (i = 2; i < 20; ++i) {
    data[i] = data[i - 2] + data[i - 1];
  }
}

void release_memory(int *data) {
  free(data);
}

void run_malloc_free_exercise(void) {
  puts("Malloc/free exercises");
  puts("------------------------------\n");
  int *data = reserve_memory();
  initialise_memory(data);
  manipulate_data(data);
  int i;
  for (i = 0; i < 20; ++i) {
    printf("%d, ", data[i]);
  }
  release_memory(data);
  puts("\n\n");
}
