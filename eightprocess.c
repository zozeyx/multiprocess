#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

#define NUM_PROCESSES 8
#define MAX_INT 1000

void perform_task(int process_id, int start, int end) {
	printf("Process %d: ", process_id + 1);
	for (int i = start; i <= end; ++i) {
		printf("%d ", i * 7);
	}
	printf("\n");
}

int main() {
	pid_t pid;
	int process_id;
	int range = MAX_INT / NUM_PROCESSES;
	clock_t start, end;
	
	start = clock();
	
	for (process_id = 0; process_id < NUM_PROCESSES; ++process_id) {
		pid = fork();
		
		if (pid == 0) {
			int start_num = process_id * range + 1;
			int end_num = (process_id + 1) * range;
			if (process_id == NUM_PROCESSES - 1)
				end_num = MAX_INT;
				
		perform_task(process_id, start_num, end_num);
		exit(0);
	} else if (pid < 0) {
		fprintf(stderr, "Fork failed\n");
		return 1;
	}
}


for (int i = 0; i < NUM_PROCESSES; ++i) {
	wait(NULL);
}

end = clock();

double time = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("eight multi-processes elapsed time: %.6lf seconds\n", time);

return 0;

}
