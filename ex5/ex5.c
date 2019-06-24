// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write
// the three messages to the parent and have the parent print out
// the messages.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 16

char *msg1 = "hello world #1";
char *msg2 = "hello world #2";
char *msg3 = "hello world #3";

int main(void)
{
    // Your code here
    char inbuff[MSGSIZE];

    int p[2];

    pipe(p);

    int rc = fork();

    if (rc == -1)
    {
        // failed
        printf("fork failed");
        exit(1);
    }
    else if (rc == 0)
    {
        //child
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
        printf("Done write\n"); // here
    }
    else
    {

        waitpid(rc, NULL, 0);
        printf("Start Read\n"); // here
        //parent
        for (int i = 0; i < 3; i++)
        {
            read(p[0], inbuff, MSGSIZE);
            printf("%s\n", inbuff);
        }
    }

    return 0;
}
