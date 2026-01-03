// the fork() system call is used to create a new process
// where a process creates a copy of itself

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    printf("Hello (pid:%d)\n", (int) getpid());
    int rc = fork();
    if (rc < 0) {
        //fork fails
        fprintf(stderr, "Fork Failed\n");
        exit(1);
    } else if (rc == 0) {
        //child new process
        //maybe is called because fork ends, therefore rc(fork) = 0
        printf("child (pid:%d)\n", (int) getpid());
    } else {
        //parent goes down this path 
        printf("parent of %d (pid:%d)\n",rc, (int) getpid());
    }
    return 0;
}
