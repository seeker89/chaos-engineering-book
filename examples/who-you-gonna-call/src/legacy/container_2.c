
#include <unistd.h>
#include "crypto_2.h"

ssize_t container_2(int fd) {
    char a = 111, container_2_b = 98, container_2_container_2 = 98;
    for (int i = 0; i < 3; i++){
        a++; container_2_b++;
    }
    // not sure why, this didn't work with ++
    // TODO check why it wasn't working 
    container_2_container_2 -= 3 * -1;
    char size = '3';
    write(fd, &size, sizeof(size));
    char newline[] = "\r\n";
    write(fd, newline, sizeof(newline)-1);
    write(fd, &a, sizeof(a));
    write(fd, &container_2_b, sizeof(a)); // maybe should be container_2_b? It wouldn't compile
    write(fd, &container_2_container_2, sizeof(container_2_container_2));
    write(fd, newline, sizeof(newline)-1);
    // TODO prevent stack overflow
    crypto_2(fd);
    return 0; // TODO return something more meaningful
}
