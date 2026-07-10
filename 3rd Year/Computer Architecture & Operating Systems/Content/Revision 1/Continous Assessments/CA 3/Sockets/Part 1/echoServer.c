/*
Student ID:
Student Name: Raja M Sumeer
Module: Computer Arch & OS @ Year 3, Semester 2 (Technological University Dublin)

Date: 16/05/2026
Code Purpose:
CA3 - Sockets
Handles client sequentially
Credits: Ben Toland
*/
// Libraries

// Sockets - Part1 (Server)
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include<string.h>
#include <unistd.h>
#include <signal.h>

sig_atomic_t connected = 0; // track connection of client

// Signal handler - called when client disconnects and SIGPIPE fires
void handler(int signal_number)
{
    connected = 0;
}
 
int main()
{
 
    char str[100];
    int listen_fd, comm_fd;

    // Sigaction for calling handler when SIGPIPE fires
    struct sigaction sa;
    memset(&sa, 0, sizeof (sa));
    sa.sa_handler = &handler;

    sigaction(SIGPIPE, &sa, NULL);
 
    // setup socket
    struct sockaddr_in servaddr;
 
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
 
    // server address setup
    bzero( &servaddr, sizeof(servaddr));
 
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htons(INADDR_ANY);
    servaddr.sin_port = htons(22000);
 
    bind(listen_fd, (struct sockaddr *) &servaddr, sizeof(servaddr));
 
    listen(listen_fd, 10); // queue up to 10 connections
 
    while(1) // loop back
    {

        comm_fd = accept(listen_fd, (struct sockaddr*) NULL, NULL);
        connected = 1; // client connected

        while(connected)
        {
 
        bzero( str, 100);
 
        read(comm_fd,str,100);
 
        printf("Echoing back - %s",str);
 
        write(comm_fd, str, strlen(str)+1);

        }
 
    }
}
