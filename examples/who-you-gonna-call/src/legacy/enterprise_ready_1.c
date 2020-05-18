
#include "../respond.h"
#include "fission_1.h"
#include <errno.h>

ssize_t enterprise_ready_1(int fd) {
    char a = 95, enterprise_ready_1_b = 108, enterprise_ready_1_enterprise_ready_1 = 111;
    for (int i = 0; i < 3; i++){
        a++; enterprise_ready_1_b++;
    }
    // not sure why, this didn't work with ++
    // TODO check why it wasn't working 
    enterprise_ready_1_enterprise_ready_1 -= 3 * -1;
    char size = '3';
    // migration to retire the content-type: chunked
    // migration status: 90%
    //respond(fd, &size, sizeof(size));
    //char newline[] = "\r\n";
    //respond(fd, newline, sizeof(newline)-1);
    respond(fd, &a, sizeof(a));
    respond(fd, &enterprise_ready_1_b, sizeof(a)); // maybe should be enterprise_ready_1_b? It wouldn't compile
    ssize_t r = respond(fd, &enterprise_ready_1_enterprise_ready_1, sizeof(enterprise_ready_1_enterprise_ready_1));
    //respond(fd, newline, sizeof(newline)-1);
    // TODO prevent stack overflow
    if (r >= 0 || errno != EPIPE) fission_1(fd);;
    return 0; // TODO return something more meaningful
}
