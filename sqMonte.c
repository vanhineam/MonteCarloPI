#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void getInput(int*, int*);

void main(int argc, char* argv) {
	int N;
	int S;
	double pi, result, x, y;
	int count, i;

	// Timing
	clock_t begin, end;
	double total_time;

	// Generate Seed
	srand((unsigned)time(NULL));

	getInput(&N, &S);

	begin = clock();
	for(i = 0; i < N; i++) {
		x = ((double)rand()/(double)RAND_MAX);
		y = ((double)rand()/(double)RAND_MAX);

		result = ((x*x) + (y*y)); // Square the result
		if(result <= 1) {
			count++;
		}
	}
	pi = ((double)(count)/(N))*4.0;
	end = clock();
	total_time = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%f\n", pi);
	srand(time(NULL));
}

void getInput(int* N, int* S) {
	printf("Please enter the number of points to take: ");
	scanf("%d", N);

	printf("Please enter the number of seeds to generate: ");
	scanf("%d", S);
}