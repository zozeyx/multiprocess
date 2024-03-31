#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INT 1000

void single_process() {
	clock_t start, end;
	start = clock();
	
	for (int i = 1; i <= MAX_INT; ++i) {
		printf("%d ", i * 7);
	}
	
	end = clock();
	double time = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("\n single process elapsed time : %.6lf seconds\n", time);
}

int main() {
	single_process();
	return 0;
}
