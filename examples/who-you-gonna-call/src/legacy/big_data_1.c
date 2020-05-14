
#include <unistd.h>
#include "bleeding_edge_1.h"

ssize_t big_data_1(int fd) {
    char a = 98, big_data_1_b = 43, big_data_1_big_data_1 = 96;
    for (int i = 0; i < 3; i++){
        a++; big_data_1_b++;
    }
    // not sure why, this didn't work with ++
    // TODO check why it wasn't working 
    big_data_1_big_data_1 -= 3 * -1;
    char size = '3';
    write(fd, &size, sizeof(size));
    char newline[] = "\r\n";
    write(fd, newline, sizeof(newline)-1);
    write(fd, &a, sizeof(a));
    write(fd, &big_data_1_b, sizeof(a)); // maybe should be big_data_1_b? It wouldn't compile
    write(fd, &big_data_1_big_data_1, sizeof(big_data_1_big_data_1));
    write(fd, newline, sizeof(newline)-1);
    // TODO prevent stack overflow
    bleeding_edge_1(fd);
    return 0; // TODO return something more meaningful
}
