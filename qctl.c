#include <sys/types.h> 
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define BUFSZ 512 

int main(int argc, char *argv[]) { 
int qid; 
struct msqid_ds dsbuf; 
if(argc != 2) { 
    puts("USAGE: qctl <qid>"); 
     exit(EXIT_FAILURE); 
} 
qid = atoi(argv[1]);
if((msgctl(qid, IPC_RMID, NULL)) < 0) { 
    perror("msgctl"); 
    exit(EXIT_FAILURE); 
} 
printf("queue %d removed\n", qid); 
exit(EXIT_SUCCESS); 
} 
