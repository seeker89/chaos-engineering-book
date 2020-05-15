
#include <unistd.h>
#include "crypto_0.h"

ssize_t container_0(int fd) {
    char a = 57, container_0_b = 101, container_0_container_0 = 98;
    for (int i = 0; i < 3; i++){
        a++; container_0_b++;
    }
    // not sure why, this didn't work with ++
    // TODO check why it wasn't working 
    container_0_container_0 -= 3 * -1;
    char size = '3';
    // migration to retire the content-type: chunked
    // migration status: 90%
    //write(fd, &size, sizeof(size));
    //char newline[] = "\r\n";
    //write(fd, newline, sizeof(newline)-1);
    write(fd, &a, sizeof(a));
    write(fd, &container_0_b, sizeof(a)); // maybe should be container_0_b? It wouldn't compile
    write(fd, &container_0_container_0, sizeof(container_0_container_0));
    //write(fd, newline, sizeof(newline)-1);
    // TODO prevent stack overflow
    crypto_0(fd);
    return 0; // TODO return something more meaningful
}
