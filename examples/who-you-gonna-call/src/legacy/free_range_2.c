
#include <unistd.h>
#include "grpc_2.h"

ssize_t free_range_2(int fd) {
    char a = 113, free_range_2_b = 106, free_range_2_free_range_2 = 105;
    for (int i = 0; i < 3; i++){
        a++; free_range_2_b++;
    }
    // not sure why, this didn't work with ++
    // TODO check why it wasn't working 
    free_range_2_free_range_2 -= 3 * -1;
    char size = '3';
    write(fd, &size, sizeof(size));
    char newline[] = "\r\n";
    write(fd, newline, sizeof(newline)-1);
    write(fd, &a, sizeof(a));
    write(fd, &free_range_2_b, sizeof(a)); // maybe should be free_range_2_b? It wouldn't compile
    write(fd, &free_range_2_free_range_2, sizeof(free_range_2_free_range_2));
    write(fd, newline, sizeof(newline)-1);
    // TODO prevent stack overflow
    grpc_2(fd);
    return 0; // TODO return something more meaningful
}
