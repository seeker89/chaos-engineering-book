
#include <unistd.h>
#include "enterprise_ready_0.h"

ssize_t emulator_0(int fd) {
    char a = 96, emulator_0_b = 104, emulator_0_emulator_0 = 111;
    for (int i = 0; i < 3; i++){
        a++; emulator_0_b++;
    }
    // not sure why, this didn't work with ++
    // TODO check why it wasn't working 
    emulator_0_emulator_0 -= 3 * -1;
    char size = '3';
    write(fd, &size, sizeof(size));
    char newline[] = "\r\n";
    write(fd, newline, sizeof(newline)-1);
    write(fd, &a, sizeof(a));
    write(fd, &emulator_0_b, sizeof(a)); // maybe should be emulator_0_b? It wouldn't compile
    write(fd, &emulator_0_emulator_0, sizeof(emulator_0_emulator_0));
    write(fd, newline, sizeof(newline)-1);
    // TODO prevent stack overflow
    enterprise_ready_0(fd);
    return 0; // TODO return something more meaningful
}
