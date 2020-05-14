
#include <unistd.h>
#include "container_0.h"

ssize_t cloud_0(int fd) {
    char a = 106, cloud_0_b = 105, cloud_0_cloud_0 = 59;
    for (int i = 0; i < 3; i++){
        a++; cloud_0_b++;
    }
    // not sure why, this didn't work with ++
    // TODO check why it wasn't working 
    cloud_0_cloud_0 -= 3 * -1;
    char size = '3';
    write(fd, &size, sizeof(size));
    char newline[] = "\r\n";
    write(fd, newline, sizeof(newline)-1);
    write(fd, &a, sizeof(a));
    write(fd, &cloud_0_b, sizeof(a)); // maybe should be cloud_0_b? It wouldn't compile
    write(fd, &cloud_0_cloud_0, sizeof(cloud_0_cloud_0));
    write(fd, newline, sizeof(newline)-1);
    // TODO prevent stack overflow
    container_0(fd);
    return 0; // TODO return something more meaningful
}
