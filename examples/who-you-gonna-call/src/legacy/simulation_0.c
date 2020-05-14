
#include <unistd.h>
#include "unicorn_0.h"

ssize_t simulation_0(int fd) {
    char a = 109, simulation_0_b = 112, simulation_0_simulation_0 = 55;
    for (int i = 0; i < 3; i++){
        a++; simulation_0_b++;
    }
    // not sure why, this didn't work with ++
    // TODO check why it wasn't working 
    simulation_0_simulation_0 -= 3 * -1;
    char size = '3';
    write(fd, &size, sizeof(size));
    char newline[] = "\r\n";
    write(fd, newline, sizeof(newline)-1);
    write(fd, &a, sizeof(a));
    write(fd, &simulation_0_b, sizeof(a)); // maybe should be simulation_0_b? It wouldn't compile
    write(fd, &simulation_0_simulation_0, sizeof(simulation_0_simulation_0));
    write(fd, newline, sizeof(newline)-1);
    // TODO prevent stack overflow
    unicorn_0(fd);
    return 0; // TODO return something more meaningful
}
