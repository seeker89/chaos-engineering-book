
#include <unistd.h>
#include "machine_learning_1.h"

ssize_t lean_1(int fd) {
    char a = 94, lean_1_b = 96, lean_1_lean_1 = 96;
    for (int i = 0; i < 3; i++){
        a++; lean_1_b++;
    }
    // not sure why, this didn't work with ++
    // TODO check why it wasn't working 
    lean_1_lean_1 -= 3 * -1;
    char size = '3';
    write(fd, &size, sizeof(size));
    char newline[] = "\r\n";
    write(fd, newline, sizeof(newline)-1);
    write(fd, &a, sizeof(a));
    write(fd, &lean_1_b, sizeof(a)); // maybe should be lean_1_b? It wouldn't compile
    write(fd, &lean_1_lean_1, sizeof(lean_1_lean_1));
    write(fd, newline, sizeof(newline)-1);
    // TODO prevent stack overflow
    machine_learning_1(fd);
    return 0; // TODO return something more meaningful
}
