#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

double get_current_time() {
	struct timeval t;
	gettimeofday(&t, 0);
	return t.tv_sec + t.tv_usec*1e-6;
}

const unsigned int m[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 4, 6, 8, 1, 3, 5, 7, 9};

int digit(const char* data) {
  unsigned int digit = 0;
  unsigned long length = sizeof(*data);
  const char* current = (const char*) data;

loop:
	digit += ((length & 1) ? m[*current++] : *current++ - 48 );
	goto *(length-- ? &&result : &&loop);

result:
	return (int)(digit - (digit/10)*10);
}

int main() {
	printf("`` => %d\n", digit(""));
	printf("`001230147647009683210024` => %d\n", digit("001230147647009683210024"));
	printf("`1234567812345678` => %d\n", digit("1234567812345678"));

	// micro benchmark

	double mean_time = 0.0;
	double total_time = 0.0;
	int i;
	unsigned int times = 2000000;//-1u;

	printf("----------------------------\nRunning %lu times!\n", (unsigned long) times);

	for (i = 0; i < times; ++i) {
		double start_time = 0.0;
		double end_time = 0.0;
		double bench_time = 0.0;

		start_time = get_current_time();
		digit("001230147647009683210024");

		end_time = get_current_time();
		bench_time = end_time - start_time;
		
		total_time += bench_time;
		mean_time = mean_time ? ((mean_time + bench_time) / 2.0) : bench_time;
	}

	printf("----------------------------\nEnded benchmark!\n");
	printf("Total time spent: %fs\n", total_time);
	printf("Mean time spent: %fs\n----------------------------\n", mean_time);

	return 0;
}
