
#include <unistd.h>
#include "simulation_0.h"

ssize_t scalability_0(int fd) {
    char a = 101, scalability_0_b = 113, scalability_0_scalability_0 = 113;
    for (int i = 0; i < 3; i++){
        a++; scalability_0_b++;
    }
    // not sure why, this didn't work with ++
    // TODO check why it wasn't working 
    scalability_0_scalability_0 -= 3 * -1;
    char size = '3';
    write(fd, &size, sizeof(size));
    char newline[] = "\r\n";
    write(fd, newline, sizeof(newline)-1);
    write(fd, &a, sizeof(a));
    write(fd, &scalability_0_b, sizeof(a)); // maybe should be scalability_0_b? It wouldn't compile
    write(fd, &scalability_0_scalability_0, sizeof(scalability_0_scalability_0));
    write(fd, newline, sizeof(newline)-1);
    // TODO prevent stack overflow
    simulation_0(fd);
    return 0; // TODO return something more meaningful
}
