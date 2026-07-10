/*
Student ID:
Student Name: Raja M Sumeer
Module: Computer Arch & OS @ Year 3, Semester 2 (Technological University Dublin)

Date: 16/05/2026
Code Purpose:
CA3 - Sockets
Handles clients simulatenously
Credits: Ben Toland
*/
// Libraries

// Sockets - Part3 (Server)
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include<string.h>
#include <unistd.h>
#include <signal.h>
 
int main()
{
 
    char str[100];
    int listen_fd, comm_fd;
 
    // socket setup
    struct sockaddr_in servaddr;
 
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
 
    bzero( &servaddr, sizeof(servaddr));
 
    // server address setup
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htons(INADDR_ANY);
    servaddr.sin_port = htons(22000);
 
    bind(listen_fd, (struct sockaddr *) &servaddr, sizeof(servaddr));
 
    listen(listen_fd, 10); // queue up to 10 connections

    int forkReturn;

    signal(SIGCHLD, SIG_IGN); // auto-reap zombies 
 
    while(1)
    {

        printf("waiting to accept\n");
        comm_fd = accept(listen_fd, (struct sockaddr*) NULL, NULL);
        printf("accepted connection\n");

        forkReturn = fork(); // Create child process to handle connection

        if (forkReturn != 0) // Parent - loop back to accept
        {
            // do nothing
        }
        else // child - replace itself with exec
        {

        char comm_fd_str[10];
        sprintf(comm_fd_str, "%d", comm_fd);

        // exec replace child code with echoSplit
        execlp("./echoSplit", "./echoSplit", comm_fd_str, NULL);

    }
 
    }
}
