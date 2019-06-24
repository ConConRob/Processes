/*
Write a program that will find the average time it takes for your computer
to make a system call an empty write to stdout. Your program should use the 
`clock_gettime` procedure to time how long a single system call takes. It'll 
do this for one million iterations, and then find the average of all of those 
iterations in nanoseconds.
For some helpful documentation and examples of using time-related system calls,
visit this site: https://www.cs.rutgers.edu/~pxk/416/notes/c-tutorials/gettime.html
While the linked site does say that `clock_gettime()` does not work on OSX, this 
turns out to only be the case for OSX versions < 10.12. Anything later than that 
and `clock_gettime()` should work just fine. 
*/

#include <stdio.h>
#include <unistd.h>
#include <time.h>

#define number_iter 1000000
#define BILLION 1000000000L
struct timespec requestStart, requestEnd;

int main()
{   
    // Your code here
    clock_gettime(CLOCK_REALTIME, &requestStart);
    for(int i =0; i<BILLION; i++){
            fprintf( stdout, "" );
    }
    clock_gettime(CLOCK_REALTIME, &requestEnd);
    
    float ns = requestEnd.tv_nsec - requestStart.tv_nsec;
    float s = requestEnd.tv_sec - requestStart.tv_sec;
    float total_time =  s * BILLION + ns ;
    printf(" Total time:  %.0f ns\n Avgerage time: %f ns \n", total_time, total_time/BILLION);



    return 0;
}
