#ifndef COMMON_H
#define COMMON_H

#include <sys/time.h>

void Spin(int seconds) {
    struct timeval start, end;
    gettimeofday(&start, NULL);
    
    while (1) {
        gettimeofday(&end, NULL);
        long elapsed = (end.tv_sec - start.tv_sec) * 1000000 + 
                       (end.tv_usec - start.tv_usec);
        if (elapsed >= seconds * 1000000)
            break;
    }
}

#endif
