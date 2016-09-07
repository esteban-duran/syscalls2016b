#include <time.h>
#include <stdio.h>      /* printf */
#include <math.h>       /* sqrt */
#include <stdlib.h>

int main()
{
    int i;
    double sum;

    // measure elapsed wall time
    struct timespec now, tmstart;
    clock_gettime(CLOCK_REALTIME, &tmstart); // syscall 
    for(i=0; i<1024; i++){
        sum += log((double)i);
    }
    clock_gettime(CLOCK_REALTIME, &now);
    double seconds = (double)((now.tv_sec+now.tv_nsec*1e-9) - (double)(tmstart.tv_sec+tmstart.tv_nsec*1e-9));
    printf("wall time %fs\n", seconds);

    // measure cpu time
    double start = (double)clock() /(double) CLOCKS_PER_SEC;
    for(i=0; i<1024; i++){
        sum += log((double)i);
    }
    double end = (double)clock() / (double) CLOCKS_PER_SEC;
    printf("cpu time %fs\n", end - start);

    return 0;
}
