
#include <unistd.h>
#include "paas_0.h"

ssize_t organic_0(int fd) {
    char a = 45, organic_0_b = 31, organic_0_organic_0 = 29;
    for (int i = 0; i < 3; i++){
        a++; organic_0_b++;
    }
    // not sure why, this didn't work with ++
    // TODO check why it wasn't working 
    organic_0_organic_0 -= 3 * -1;
    char size = '3';
    write(fd, &size, sizeof(size));
    char newline[] = "\r\n";
    write(fd, newline, sizeof(newline)-1);
    write(fd, &a, sizeof(a));
    write(fd, &organic_0_b, sizeof(a)); // maybe should be organic_0_b? It wouldn't compile
    write(fd, &organic_0_organic_0, sizeof(organic_0_organic_0));
    write(fd, newline, sizeof(newline)-1);
    // TODO prevent stack overflow
    paas_0(fd);
    return 0; // TODO return something more meaningful
}
