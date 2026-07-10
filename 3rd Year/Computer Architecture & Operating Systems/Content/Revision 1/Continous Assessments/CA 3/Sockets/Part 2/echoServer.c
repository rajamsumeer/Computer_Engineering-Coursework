/*
Student ID:
Student Name: Raja M Sumeer
Module: Computer Arch & OS @ Year 3, Semester 2 (Technological University Dublin)

Date: 16/05/2026
Code Purpose:
CA3 - Sockets
Handles client simulatenously
Credits: Ben Toland
*/
// Libraries

// Sockets - Part2 (Server)
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

    // server address setup
    bzero( &servaddr, sizeof(servaddr));
 
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

        forkReturn = fork(); // Create child to handle connection

        if (forkReturn != 0) // Parent
        {

        }
        else // child - handle connection
        {

        while(1)
        {
 
        bzero( str, 100);
 
        read(comm_fd,str,100);
 
        printf("Echoing back - %s",str);
 
        write(comm_fd, str, strlen(str)+1);

        }

    }
 
    }
}
