#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DATA_SIZE 32768
static int DATA[DATA_SIZE];
#define ITERATIONS 102400
static const int RAND_MID = RAND_MAX / 2;

void initialise(void) {
  srand(time(NULL));
  int i;
  for (i = 0; i < DATA_SIZE; ++i)
    DATA[i] = rand();
}

static clock_t start;
void start_clock() {
  start = clock();
}

void end_clock() {
  const clock_t end = clock();
  const float seconds = (float)(end - start) / CLOCKS_PER_SEC;
  printf("Runtime: %fs\n", seconds);
}

int calculate(void) {
  int sum = 0;
  int i, j;
  for (j = 0; j < ITERATIONS; ++j)
    for (i = 0; i < DATA_SIZE; ++i)
        sum += DATA[i];
  return sum;
}

void scenario1(void) {
  puts("Scenario 1...");

  start_clock();
  calculate();
  end_clock();
}

int compare_int(const void *a, const void *b) {
  const int lhs = *(const int *) a;
  const int rhs = *(const int *) b;
  return lhs < rhs ? -1 : lhs > rhs ? 1 : 0;
}

void scenario2(void) {
  puts("\nScenario 2...");

  start_clock();
  qsort(DATA, DATA_SIZE, sizeof(int), compare_int);
  calculate();
  end_clock();
}

void run_branch_prediction_exercise(void) {
  puts("Branch prediction exercise");
  puts("------------------------------\n");
  initialise();
  scenario1();
  scenario2();
  puts("\n");
}
