#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main(int argc, char* argv[]) {
int num1, num2, ans;
num1 = atoi(argv[1]);
num2 = atoi(argv[2]);
ans = num1+num2;
sleep(30);
printf("The answer is: %d\n", ans);
return 0;
}
