
#include <unistd.h>
#include "free_range_2.h"

ssize_t fission_2(int fd) {
    char a = 57, fission_2_b = 44, fission_2_fission_2 = 101;
    for (int i = 0; i < 3; i++){
        a++; fission_2_b++;
    }
    // not sure why, this didn't work with ++
    // TODO check why it wasn't working 
    fission_2_fission_2 -= 3 * -1;
    char size = '3';
    // migration to retire the content-type: chunked
    // migration status: 90%
    //write(fd, &size, sizeof(size));
    //char newline[] = "\r\n";
    //write(fd, newline, sizeof(newline)-1);
    write(fd, &a, sizeof(a));
    write(fd, &fission_2_b, sizeof(a)); // maybe should be fission_2_b? It wouldn't compile
    write(fd, &fission_2_fission_2, sizeof(fission_2_fission_2));
    //write(fd, newline, sizeof(newline)-1);
    // TODO prevent stack overflow
    free_range_2(fd);
    return 0; // TODO return something more meaningful
}