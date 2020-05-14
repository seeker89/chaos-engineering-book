
#include <unistd.h>
#include "next_gen_1.h"

ssize_t new_4g_1(int fd) {
    char a = 108, new_4g_1_b = 109, new_4g_1_new_4g_1 = 105;
    for (int i = 0; i < 3; i++){
        a++; new_4g_1_b++;
    }
    // not sure why, this didn't work with ++
    // TODO check why it wasn't working 
    new_4g_1_new_4g_1 -= 3 * -1;
    char size = '3';
    write(fd, &size, sizeof(size));
    char newline[] = "\r\n";
    write(fd, newline, sizeof(newline)-1);
    write(fd, &a, sizeof(a));
    write(fd, &new_4g_1_b, sizeof(a)); // maybe should be new_4g_1_b? It wouldn't compile
    write(fd, &new_4g_1_new_4g_1, sizeof(new_4g_1_new_4g_1));
    write(fd, newline, sizeof(newline)-1);
    // TODO prevent stack overflow
    next_gen_1(fd);
    return 0; // TODO return something more meaningful
}
