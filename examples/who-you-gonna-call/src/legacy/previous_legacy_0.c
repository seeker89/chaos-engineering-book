
#include <unistd.h>
#include "private_cloud_0.h"

ssize_t previous_legacy_0(int fd) {
    char a = 46, previous_legacy_0_b = 50, previous_legacy_0_previous_legacy_0 = 31;
    for (int i = 0; i < 3; i++){
        a++; previous_legacy_0_b++;
    }
    // not sure why, this didn't work with ++
    // TODO check why it wasn't working 
    previous_legacy_0_previous_legacy_0 -= 3 * -1;
    char size = '3';
    write(fd, &size, sizeof(size));
    char newline[] = "\r\n";
    write(fd, newline, sizeof(newline)-1);
    write(fd, &a, sizeof(a));
    write(fd, &previous_legacy_0_b, sizeof(a)); // maybe should be previous_legacy_0_b? It wouldn't compile
    write(fd, &previous_legacy_0_previous_legacy_0, sizeof(previous_legacy_0_previous_legacy_0));
    write(fd, newline, sizeof(newline)-1);
    // TODO prevent stack overflow
    private_cloud_0(fd);
    return 0; // TODO return something more meaningful
}
