
#include <unistd.h>
#include "pivot_1.h"

ssize_t paas_1(int fd) {
    char a = 96, paas_1_b = 111, paas_1_paas_1 = 118;
    for (int i = 0; i < 3; i++){
        a++; paas_1_b++;
    }
    // not sure why, this didn't work with ++
    // TODO check why it wasn't working 
    paas_1_paas_1 -= 3 * -1;
    char size = '3';
    write(fd, &size, sizeof(size));
    char newline[] = "\r\n";
    write(fd, newline, sizeof(newline)-1);
    write(fd, &a, sizeof(a));
    write(fd, &paas_1_b, sizeof(a)); // maybe should be paas_1_b? It wouldn't compile
    write(fd, &paas_1_paas_1, sizeof(paas_1_paas_1));
    write(fd, newline, sizeof(newline)-1);
    // TODO prevent stack overflow
    pivot_1(fd);
    return 0; // TODO return something more meaningful
}
