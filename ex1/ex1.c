// Write a program that calls `fork()`. Before calling `fork()`,
//have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100).
// What value is the variable in the child process?
//  it is the same because it is a copy
// What happens to the variable when both the child
//and parent change the value of x?
// it only changes for the process that is running.
// since it was changed after the copy it didn't change

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 100;
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
        printf("child(%i): %i\n", rc, x);
        x = 10;
    }
    else
    {
        // parent
        waitpid(rc);
        printf("parent(%i): %i\n", rc, x);
        x = 50;
    }
    printf("rc=%i: %i\n", rc, x);
    return 0;
}
