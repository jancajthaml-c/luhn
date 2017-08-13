/////////////////////////////////

const int m[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0, 2, 4, 6, 8, 1, 3, 5, 7, 9 };

int digit(const char* data) {
  int d = 0;
  unsigned long length = sizeof(*data);
  const char* current = (const char*) data;  
loop:
  d += ((length & 1) ? m[*current++] : (*current++ - 48));
  goto *(length-- ? &&result : &&loop);
result:
  return (d - (d/10)*10);
}

/////////////////////////////////

// FIXME separate to main.c

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
	printf("\nRunning \"unit\" tests \n");

	printf("`` => %d\n", digit(""));
	printf("`001230147647009683210024` => %d\n", digit("001230147647009683210024"));
	printf("`1234567812345678` => %d\n", digit("1234567812345678"));

	// micro benchmark

	int i;
	int j;
	unsigned int times = 20000000;//-1u;

	printf("\nRunning benchmark %lu times \n", (unsigned long) times);

	double best_time = 10000000000.0;
	double total_time = 0;
	double clock_cost = 0;

	struct timespec t1;
	struct timespec t2;

	for (j = 0; j < times; ++j) {
		clock_gettime(CLOCK_MONOTONIC_RAW, &t1);
		clock_gettime(CLOCK_MONOTONIC_RAW, &t2);
		if (1 > 2) {
			;
		}
		clock_cost += diff(t1.tv_nsec, t2.tv_nsec);
	}

	clock_cost /= times;

	for (i = 0; i < times; ++i) {
		clock_gettime(CLOCK_MONOTONIC_RAW, &t1);
		digit("49927398716499273987164992739871649927398716499273987164992739871649927398716499273987164992739871649927398716499273987164992739871649927398716499273987164992739871649927398716");
		clock_gettime(CLOCK_MONOTONIC_RAW, &t2);
		double time = diff(t1.tv_nsec, t2.tv_nsec);
		if (time < best_time) {
			best_time = time;
		}
		total_time += time;
	}

	printf("\nmedian: %f ns/op\nbest:   %f ns/op\n\n", (total_time/times/clock_cost), (best_time/clock_cost));

	return 0;
}

