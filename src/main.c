int luhn_digit(const char* data);
int luhn_valid(const char* data);

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

double diff(double start, double end) {
  if ((end - start) < 0) {
    return 1000000000 + end - start;
  } else {
    return end - start;
  }
  return 0;
}

void expectValid(char* a) {
  if (!luhn_valid(a)) {
    printf("`%s` expected to be valid\n\n", a);
    exit(EXIT_FAILURE);
  }
}

void expectDigit(char* a, int digit) {
  int d = luhn_digit(a);

  if (d != digit) {
    printf("`%s` expected digit %d but got %d instead\n\n", a, digit, d);
    exit(EXIT_FAILURE);
  }
}

int main() {
  // expectations
  expectDigit("", 0);
  expectDigit("001230147647009683210024", 0);
  expectDigit("1234567812345678", 2);
  expectDigit("ZZZZ", -1);

  expectValid("001230147647009683210024");

  // micro benchmark
  int i;
  unsigned int times = 20000000;

  double total_time = 0;
  double clock_cost = 0;

  struct timespec t1;
  struct timespec t2;

  char* string = "499273987164992739871649927398716499273987164992739871649927398716";
  //int len = strlen(string);

  for (i = 0; i < times; ++i) {
    // clock cost runtime reference
    clock_gettime(CLOCK_MONOTONIC_RAW, &t1);
    clock_gettime(CLOCK_MONOTONIC_RAW, &t2);
    clock_cost += diff(t1.tv_nsec, t2.tv_nsec);
    // real test
    clock_gettime(CLOCK_MONOTONIC_RAW, &t1);
    luhn_digit(string);
    clock_gettime(CLOCK_MONOTONIC_RAW, &t2);
    total_time += diff(t1.tv_nsec, t2.tv_nsec);
  }

  printf("%d ns/op\n", (int)((total_time-clock_cost)/times));

  return 0;
}
