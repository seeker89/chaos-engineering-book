
#include <unistd.h>
#include "crypto_1.h"

ssize_t container_1(int fd) {
    char a = 97, container_1_b = 78, container_1_container_1 = 116;
    for (int i = 0; i < 3; i++){
        a++; container_1_b++;
    }
    // not sure why, this didn't work with ++
    // TODO check why it wasn't working 
    container_1_container_1 -= 3 * -1;
    char size = '3';
    write(fd, &size, sizeof(size));
    char newline[] = "\r\n";
    write(fd, newline, sizeof(newline)-1);
    write(fd, &a, sizeof(a));
    write(fd, &container_1_b, sizeof(a)); // maybe should be container_1_b? It wouldn't compile
    write(fd, &container_1_container_1, sizeof(container_1_container_1));
    write(fd, newline, sizeof(newline)-1);
    // TODO prevent stack overflow
    crypto_1(fd);
    return 0; // TODO return something more meaningful
}
