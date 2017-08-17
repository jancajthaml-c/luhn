int luhn_digit(const char* data, unsigned long length);

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

void expectDigit(char* a, int digit) {
	int d = luhn_digit(a, strlen(a));

	if (d != digit) {
		printf("`%s` expected digit %d but got %d instead\n\n", a, digit, d);
		exit(EXIT_FAILURE);
	}
}

int main() {
	printf("\nRunning unit tests\n");

	// expectations
	expectDigit("", 0);
	expectDigit("001230147647009683210024", 0);
	expectDigit("1234567812345678", 8);
	expectDigit("ZZZZ", -1);

	printf("passed");

	// micro benchmark

	int i;
	unsigned int times = 20000000;

	printf("\n\nRunning benchmark %lu times \n", (unsigned long) times);

	double total_time = 0;
	double clock_cost = 0;

	struct timespec t1;
	struct timespec t2;

	char* string = "49927398716"; //"49927398716499273987164992739871649927398716499273987164992739871649927398716499273987164992739871649927398716499273987164992739871649927398716499273987164992739871649927398716";
	int len = strlen(string);

	for (i = 0; i < times; ++i) {
		// clock cost runtime reference
		clock_gettime(CLOCK_MONOTONIC_RAW, &t1);
		clock_gettime(CLOCK_MONOTONIC_RAW, &t2);
		clock_cost += diff(t1.tv_nsec, t2.tv_nsec);
		// real test
		clock_gettime(CLOCK_MONOTONIC_RAW, &t1);
		luhn_digit(string, len);
		clock_gettime(CLOCK_MONOTONIC_RAW, &t2);
		total_time += diff(t1.tv_nsec, t2.tv_nsec);
	}

	printf("median: %f ns/op\n\n", ((total_time-clock_cost)/times));

	return 0;
}