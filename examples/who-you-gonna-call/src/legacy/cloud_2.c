
#include <unistd.h>
#include "container_2.h"

ssize_t cloud_2(int fd) {
    char a = 105, cloud_2_b = 112, cloud_2_cloud_2 = 96;
    for (int i = 0; i < 3; i++){
        a++; cloud_2_b++;
    }
    // not sure why, this didn't work with ++
    // TODO check why it wasn't working 
    cloud_2_cloud_2 -= 3 * -1;
    char size = '3';
    write(fd, &size, sizeof(size));
    char newline[] = "\r\n";
    write(fd, newline, sizeof(newline)-1);
    write(fd, &a, sizeof(a));
    write(fd, &cloud_2_b, sizeof(a)); // maybe should be cloud_2_b? It wouldn't compile
    write(fd, &cloud_2_cloud_2, sizeof(cloud_2_cloud_2));
    write(fd, newline, sizeof(newline)-1);
    // TODO prevent stack overflow
    container_2(fd);
    return 0; // TODO return something more meaningful
}
