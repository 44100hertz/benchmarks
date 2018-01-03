#define time _time
#include <time.h>
#undef time

double time()
{
        struct timespec t;
        clock_gettime(CLOCK_MONOTONIC, &t);
        return t.tv_sec + t.tv_nsec * 1.0e-9;
}
