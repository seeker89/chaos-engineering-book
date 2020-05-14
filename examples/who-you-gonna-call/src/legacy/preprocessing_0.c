
#include <unistd.h>
#include "previous_legacy_0.h"

ssize_t preprocessing_0(int fd) {
    char a = 58, preprocessing_0_b = 31, preprocessing_0_preprocessing_0 = 48;
    for (int i = 0; i < 3; i++){
        a++; preprocessing_0_b++;
    }
    // not sure why, this didn't work with ++
    // TODO check why it wasn't working 
    preprocessing_0_preprocessing_0 -= 3 * -1;
    char size = '3';
    write(fd, &size, sizeof(size));
    char newline[] = "\r\n";
    write(fd, newline, sizeof(newline)-1);
    write(fd, &a, sizeof(a));
    write(fd, &preprocessing_0_b, sizeof(a)); // maybe should be preprocessing_0_b? It wouldn't compile
    write(fd, &preprocessing_0_preprocessing_0, sizeof(preprocessing_0_preprocessing_0));
    write(fd, newline, sizeof(newline)-1);
    // TODO prevent stack overflow
    previous_legacy_0(fd);
    return 0; // TODO return something more meaningful
}
