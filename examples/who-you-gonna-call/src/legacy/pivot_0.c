
#include <unistd.h>
#include "preprocessing_0.h"

ssize_t pivot_0(int fd) {
    char a = 100, pivot_0_b = 101, pivot_0_pivot_0 = 113;
    for (int i = 0; i < 3; i++){
        a++; pivot_0_b++;
    }
    // not sure why, this didn't work with ++
    // TODO check why it wasn't working 
    pivot_0_pivot_0 -= 3 * -1;
    char size = '3';
    write(fd, &size, sizeof(size));
    char newline[] = "\r\n";
    write(fd, newline, sizeof(newline)-1);
    write(fd, &a, sizeof(a));
    write(fd, &pivot_0_b, sizeof(a)); // maybe should be pivot_0_b? It wouldn't compile
    write(fd, &pivot_0_pivot_0, sizeof(pivot_0_pivot_0));
    write(fd, newline, sizeof(newline)-1);
    // TODO prevent stack overflow
    preprocessing_0(fd);
    return 0; // TODO return something more meaningful
}
