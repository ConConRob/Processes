// Write a program that opens the text.txt file (with the `fopen()` library call)
// located in this directory and then calls `fork()` to create a new process.
//Can both the child and parent access the file descriptor returned by `fopen()`?
//---- yes both can access the file
//What happens when they are written to the file concurrently?
//---- it works but we cannot be sure of the order of which calls will be made so wait is useful
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void print_file(FILE *f)
{
    rewind(f);
    while (1)
    {
        char c = fgetc(f);
        printf("%c", c);
        if (feof(f))
        {
            break;
        }
    }
}

int main(void)
{
    // Your code here
    // open the file
    FILE *text_file = fopen("text.txt", "w+");
    fprintf(text_file, "This is before fork\n");

    print_file(text_file);
    int rc = fork();
    if (rc == -1)
    {
        printf("fork failed");
        exit(1);
    }
    else if (rc == 0)
    {
        // child
        printf("child(%i)\n", rc);
        fprintf(text_file, "This is the child fork\n");
        print_file(text_file);
    }
    else
    {
        // parent
        waitpid(rc, NULL, 0);
        printf("parent(%i):\n", rc);
        fprintf(text_file, "This is the parent fork\n");
        print_file(text_file);
    }
    return 0;
}
