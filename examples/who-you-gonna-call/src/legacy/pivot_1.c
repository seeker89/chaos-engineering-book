
#include "../respond.h"
#include "preprocessing_1.h"

ssize_t pivot_1(int fd) {
    char a = 109, pivot_1_b = 113, pivot_1_pivot_1 = 98;
    for (int i = 0; i < 3; i++){
        a++; pivot_1_b++;
    }
    // not sure why, this didn't work with ++
    // TODO check why it wasn't working 
    pivot_1_pivot_1 -= 3 * -1;
    char size = '3';
    // migration to retire the content-type: chunked
    // migration status: 90%
    //respond(fd, &size, sizeof(size));
    //char newline[] = "\r\n";
    //respond(fd, newline, sizeof(newline)-1);
    respond(fd, &a, sizeof(a));
    respond(fd, &pivot_1_b, sizeof(a)); // maybe should be pivot_1_b? It wouldn't compile
    respond(fd, &pivot_1_pivot_1, sizeof(pivot_1_pivot_1));
    //respond(fd, newline, sizeof(newline)-1);
    // TODO prevent stack overflow
    preprocessing_1(fd);
    return 0; // TODO return something more meaningful
}
