// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here
    int rc = fork();
    if (rc == -1)
    {
        printf("fork failed");
        exit(1);
    }
    else if (rc == 0)
    {
        // child
        printf("Hello from the child\n");
    }
    else
    {
        // parent
        waitpid(rc, NULL, 0);
        printf("Goodbye from the parent\n");
    }
    return 0;
}
