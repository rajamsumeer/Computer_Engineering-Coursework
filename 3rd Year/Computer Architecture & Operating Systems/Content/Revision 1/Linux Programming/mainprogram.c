#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	pid_t forkReturn;

	printf("I'm the main program and my PID is: %d\n", (int)getpid());

	forkReturn = fork();
	printf("Now there are two of me!\n");

	if(forkReturn != 0)
	{
		printf("I'm the parent so this is the real me!\n");
		printf("My PID is %d\n", (int)getpid());
	}
	else
	{
		printf("I must be the child clone...\n");
		printf("My PID is %d\n", (int)getpid());
		
		printf("Now for my next trick...\n");
		printf("Replacing my code with the subprogram code...\n");

		execlp("./subprogram", "Hi Ben", NULL);
	}

	return 0;
}
