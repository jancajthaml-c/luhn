/////////////////////////////////

// FIXME separate to main.c

#include "luhn.h"

#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

double diff(double start, double end) {
  double temp;
  if ((end - start) < 0) {
  	return 1000000000 + end - start;
  } else {
		return end - start;
  }
  return temp;
}

int main() {
	printf("\nRunning unit tests \n");

	// expectations

	if (digit("") != 0) {
		return 1;
	}
	if (digit("001230147647009683210024") != 0) {
		return 1;
	}

	if (digit("1234567812345678") == 0) {
		return 1;
	}

	if (digit("ZZZZ") != -1) {
		return 1;
	}

	printf("passed");

	// micro benchmark

	int i;
	unsigned int times = 20000000;//-1u;

	printf("\n\nRunning benchmark %lu times \n", (unsigned long) times);

	double total_time = 0;
	double clock_cost = 0;

	struct timespec t1;
	struct timespec t2;

	for (i = 0; i < times; ++i) {
		clock_gettime(CLOCK_MONOTONIC_RAW, &t1);
		clock_gettime(CLOCK_MONOTONIC_RAW, &t2);
		clock_cost += diff(t1.tv_nsec, t2.tv_nsec);

		clock_gettime(CLOCK_MONOTONIC_RAW, &t1);
		digit("49927398716499273987164992739871649927398716499273987164992739871649927398716499273987164992739871649927398716499273987164992739871649927398716499273987164992739871649927398716");
		clock_gettime(CLOCK_MONOTONIC_RAW, &t2);
		total_time += diff(t1.tv_nsec, t2.tv_nsec);
	}

	printf("median: %f ns/op\n\n", ((total_time-clock_cost)/times));

	return 0;
}