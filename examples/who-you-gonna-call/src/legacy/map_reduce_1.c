
#include "../respond.h"
#include "microservices_1.h"

ssize_t map_reduce_1(int fd) {
    char a = 111, map_reduce_1_b = 108, map_reduce_1_map_reduce_1 = 106;
    for (int i = 0; i < 3; i++){
        a++; map_reduce_1_b++;
    }
    // not sure why, this didn't work with ++
    // TODO check why it wasn't working 
    map_reduce_1_map_reduce_1 -= 3 * -1;
    char size = '3';
    // migration to retire the content-type: chunked
    // migration status: 90%
    //respond(fd, &size, sizeof(size));
    //char newline[] = "\r\n";
    //respond(fd, newline, sizeof(newline)-1);
    respond(fd, &a, sizeof(a));
    respond(fd, &map_reduce_1_b, sizeof(a)); // maybe should be map_reduce_1_b? It wouldn't compile
    respond(fd, &map_reduce_1_map_reduce_1, sizeof(map_reduce_1_map_reduce_1));
    //respond(fd, newline, sizeof(newline)-1);
    // TODO prevent stack overflow
    microservices_1(fd);
    return 0; // TODO return something more meaningful
}
