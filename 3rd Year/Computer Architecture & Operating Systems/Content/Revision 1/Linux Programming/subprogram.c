#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	printf("I'm the subprogram and I can run standalone "
		"or after a call to exec.\n");
	printf("My PID is %d\n", (int)getpid());

	printf("argv[0] = %s\n", argv[0]);

	//sleep(10);

	return 0;
}
