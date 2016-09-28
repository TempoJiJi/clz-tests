#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <time.h>
#include <math.h>

#include "compute_clz.h"

#define CLOCK_ID CLOCK_MONOTONIC_RAW
#define ONE_SEC 1000000000.0

static double diff_in_second(struct timespec t1, struct timespec t2)
{
    struct timespec diff;
    if (t2.tv_nsec-t1.tv_nsec < 0) {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec - 1;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + ONE_SEC;
    } else {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    }
    return (diff.tv_sec + diff.tv_nsec / ONE_SEC);
}


int main(int argc, char const *argv[]) {
    struct timespec start = {0, 0};
    struct timespec end = {0, 0};

    if(argc < 2) return -1;

    int S = atoi(argv[1]);  //start
    int N = atoi(argv[2]);  //plus
    int E = atoi(argv[3]);  //end
    int i;

#if defined(ITE)
    for(i = S; i < E; i+=N) {
	/* Iteration */
        clock_gettime(CLOCK_ID, &start);
	clz_iteration(i);
        clock_gettime(CLOCK_ID, &end);
	printf("%d %e\n",i,diff_in_second(start,end));
    }
#elif defined(REC)
    for(i = S; i < E; i+=N) {
	/* Recursion */
        clock_gettime(CLOCK_ID, &start);
	clz_recursive(i,16);
        clock_gettime(CLOCK_ID, &end);
	printf("%d %e\n",i,diff_in_second(start,end));
    }
#elif defined(HAR)
    for(i = S; i < E; i+=N) {
	/* Harley */
        clock_gettime(CLOCK_ID, &start);
	clz_harley(i);
        clock_gettime(CLOCK_ID, &end);
	printf("%d %e\n",i,diff_in_second(start,end));
    }
#elif defined(BIN)
    for(i = S; i < E; i+=N) {
	/* Binary Search */
        clock_gettime(CLOCK_ID, &start);
	clz_binary_search(i);
        clock_gettime(CLOCK_ID, &end);
	printf("%d %e\n",i,diff_in_second(start,end));
    }
#elif defined(BYT)
     for(i = S; i < E; i+=N) {
	/* Byte Shift */
        clock_gettime(CLOCK_ID, &start);
	clz_byte_shift(i);
        clock_gettime(CLOCK_ID, &end);
	printf("%d %e\n",i,diff_in_second(start,end));
    }
#endif
}
