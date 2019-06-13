// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?
// they allow for diffrent ways of calling a exec file
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

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
        printf("child(%i)\n", getpid());
        char *args[3];
        args[0] = strdup("/bin/ls");
        args[1] = NULL;
        execv(args[0], args);
        printf("If you see this the exec was not run.");
    }
    else
    {
        // parent
        waitpid(rc, NULL, 0);
        printf("parent(%i):\n", rc);
    }
    return 0;
}
