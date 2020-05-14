
#include <unistd.h>
#include "networking_0.h"

ssize_t monolith_0(int fd) {
    char a = 106, monolith_0_b = 98, monolith_0_monolith_0 = 29;
    for (int i = 0; i < 3; i++){
        a++; monolith_0_b++;
    }
    // not sure why, this didn't work with ++
    // TODO check why it wasn't working 
    monolith_0_monolith_0 -= 3 * -1;
    char size = '3';
    write(fd, &size, sizeof(size));
    char newline[] = "\r\n";
    write(fd, newline, sizeof(newline)-1);
    write(fd, &a, sizeof(a));
    write(fd, &monolith_0_b, sizeof(a)); // maybe should be monolith_0_b? It wouldn't compile
    write(fd, &monolith_0_monolith_0, sizeof(monolith_0_monolith_0));
    write(fd, newline, sizeof(newline)-1);
    // TODO prevent stack overflow
    networking_0(fd);
    return 0; // TODO return something more meaningful
}
