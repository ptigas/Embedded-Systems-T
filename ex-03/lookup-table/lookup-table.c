#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Model function.
 */
static const double MAX_RADIAN = 2.0 * M_PI;
static const double A = 50.0;
static const double p1 = 0.25 * M_PI;
static const double p2 = 0.5 * M_PI;
double model_function(double input) {
  return A * sin(input) * sin(input + p1) * cos(input + p2);
}

/**
 * Default lookup table.
 */
#define LOOKUP_TABLE_SIZE 1000
typedef unsigned int tindex;

static double DEFAULT_MODEL_DATA[LOOKUP_TABLE_SIZE];
void fill_model_data() {
  // TODO: Implement
}

double fast_model_function(double rad) {
  // TODO: Implement
  return 0.0;
}

/**
 * Scaled lookup table.
 */
struct Entry {
};
static struct Entry SCALED_MODEL_DATA[LOOKUP_TABLE_SIZE];
void fill_scaled_model_data() {
  // TODO: Implement
}

double scaled_fast_model_function(double rad) {
  // TODO: Implement
  return 0.0;
}

// gnuplot output
void print_gnuplot_datfile() {
  FILE *pFile = fopen("gnuplot.dat", "w");
  const unsigned int nPoints = 100000;
  int i;
  for (i = 0; i < nPoints; ++i) {
    double angle = (double) i / (double) nPoints * MAX_RADIAN;
    fprintf(pFile, "%f\t%f\t%f\t%f\n", angle, model_function(angle), fast_model_function(angle), scaled_fast_model_function(angle));
  }
  fclose(pFile);
}

int main(void) {
  // TODO: Test your implementations
  // TODO: Compare performance gains

  // Print gnuplot data file.
  print_gnuplot_datfile();
  return 0;
}
