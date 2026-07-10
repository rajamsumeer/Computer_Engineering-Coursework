/*
Student ID:
Student Name: Raja M Sumeer
Module: Computer Arch & OS @ Year 3, Semester 2 (Technological University Dublin)

Date: 16/05/2026
Code Purpose:
CA3 - Sockets
Credits: Ben Toland
*/
// Libraries

// Sockets - Part3 (EXECLP)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char str[100];

    int comm_fd = atoi(argv[1]); // get back socket file descriptor

    printf("Replaced child code - PID: %d\n", (int)getpid());

    while(1)
    {
        bzero( str, 100);
 
        read(comm_fd,str,100);
 
        printf("Echoing back - %s",str);
 
        write(comm_fd, str, strlen(str)+1);
    }
}