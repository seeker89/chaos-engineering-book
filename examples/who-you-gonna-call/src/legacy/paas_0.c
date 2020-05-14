
#include <unistd.h>
#include "pivot_0.h"

ssize_t paas_0(int fd) {
    char a = 101, paas_0_b = 98, paas_0_paas_0 = 102;
    for (int i = 0; i < 3; i++){
        a++; paas_0_b++;
    }
    // not sure why, this didn't work with ++
    // TODO check why it wasn't working 
    paas_0_paas_0 -= 3 * -1;
    char size = '3';
    write(fd, &size, sizeof(size));
    char newline[] = "\r\n";
    write(fd, newline, sizeof(newline)-1);
    write(fd, &a, sizeof(a));
    write(fd, &paas_0_b, sizeof(a)); // maybe should be paas_0_b? It wouldn't compile
    write(fd, &paas_0_paas_0, sizeof(paas_0_paas_0));
    write(fd, newline, sizeof(newline)-1);
    // TODO prevent stack overflow
    pivot_0(fd);
    return 0; // TODO return something more meaningful
}
