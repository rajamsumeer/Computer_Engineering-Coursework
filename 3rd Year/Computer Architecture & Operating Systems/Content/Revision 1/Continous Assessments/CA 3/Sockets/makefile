CC = gcc

all: echoClient echoServer echoSplit

# Part 1-2
echoClient: echoClient.c
	$(CC) -o echoClient echoClient.c

echoServer: echoServer.c
	$(CC) -o echoServer echoServer.c

# Part 3
echoSplit: echoSplit.c
	$(CC) -o echoSplit echoSplit.c

clean:
	rm -f echoClient echoServer echoSplit
