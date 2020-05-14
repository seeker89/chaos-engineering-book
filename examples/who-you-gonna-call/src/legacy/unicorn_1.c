
#include <unistd.h>
#include "virtualization_1.h"

ssize_t unicorn_1(int fd) {
    char a = 56, unicorn_1_b = 29, unicorn_1_unicorn_1 = 109;
    for (int i = 0; i < 3; i++){
        a++; unicorn_1_b++;
    }
    // not sure why, this didn't work with ++
    // TODO check why it wasn't working 
    unicorn_1_unicorn_1 -= 3 * -1;
    char size = '3';
    write(fd, &size, sizeof(size));
    char newline[] = "\r\n";
    write(fd, newline, sizeof(newline)-1);
    write(fd, &a, sizeof(a));
    write(fd, &unicorn_1_b, sizeof(a)); // maybe should be unicorn_1_b? It wouldn't compile
    write(fd, &unicorn_1_unicorn_1, sizeof(unicorn_1_unicorn_1));
    write(fd, newline, sizeof(newline)-1);
    // TODO prevent stack overflow
    virtualization_1(fd);
    return 0; // TODO return something more meaningful
}
