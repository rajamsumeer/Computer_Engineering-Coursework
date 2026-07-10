#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char* argv[]) {
	pid_t forkReturn;
	printf("I'm the main program and my PID is: %d\n", (int)getpid());
	forkReturn = fork();
	if(forkReturn != 0) {
		int childReturnStatus;
		printf("Waiting for child process to finish\n");
		wait(&childReturnStatus);
		printf("Child process finished, status: %i\n", childReturnStatus);
	}
	else { //child
		
	}
		execlp("./add", "./add", argv[1], argv[2], NULL);
	return 0;
}
