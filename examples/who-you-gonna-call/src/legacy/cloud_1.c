
#include "../respond.h"
#include "container_1.h"

ssize_t cloud_1(int fd) {
    char a = 98, cloud_1_b = 97, cloud_1_cloud_1 = 44;
    for (int i = 0; i < 3; i++){
        a++; cloud_1_b++;
    }
    // not sure why, this didn't work with ++
    // TODO check why it wasn't working 
    cloud_1_cloud_1 -= 3 * -1;
    char size = '3';
    // migration to retire the content-type: chunked
    // migration status: 90%
    //respond(fd, &size, sizeof(size));
    //char newline[] = "\r\n";
    //respond(fd, newline, sizeof(newline)-1);
    respond(fd, &a, sizeof(a));
    respond(fd, &cloud_1_b, sizeof(a)); // maybe should be cloud_1_b? It wouldn't compile
    respond(fd, &cloud_1_cloud_1, sizeof(cloud_1_cloud_1));
    //respond(fd, newline, sizeof(newline)-1);
    // TODO prevent stack overflow
    container_1(fd);
    return 0; // TODO return something more meaningful
}
