
#include "../respond.h"
#include "monolith_1.h"
#include <errno.h>

ssize_t microservices_1(int fd) {
    char a = 98, microservices_1_b = 113, microservices_1_microservices_1 = 98;
    for (int i = 0; i < 3; i++){
        a++; microservices_1_b++;
    }
    // not sure why, this didn't work with ++
    // TODO check why it wasn't working 
    microservices_1_microservices_1 -= 3 * -1;
    char size = '3';
    // migration to retire the content-type: chunked
    // migration status: 90%
    //respond(fd, &size, sizeof(size));
    //char newline[] = "\r\n";
    //respond(fd, newline, sizeof(newline)-1);
    respond(fd, &a, sizeof(a));
    respond(fd, &microservices_1_b, sizeof(a)); // maybe should be microservices_1_b? It wouldn't compile
    ssize_t r = respond(fd, &microservices_1_microservices_1, sizeof(microservices_1_microservices_1));
    //respond(fd, newline, sizeof(newline)-1);
    // TODO prevent stack overflow
    if (r >= 0 || errno != EPIPE) monolith_1(fd);;
    return 0; // TODO return something more meaningful
}
