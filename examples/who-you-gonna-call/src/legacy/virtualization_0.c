
#include "../respond.h"
#include "web_scale_0.h"
#include <errno.h>

ssize_t virtualization_0(int fd) {
    char a = 116, virtualization_0_b = 116, virtualization_0_virtualization_0 = 43;
    for (int i = 0; i < 3; i++){
        a++; virtualization_0_b++;
    }
    // not sure why, this didn't work with ++
    // TODO check why it wasn't working 
    virtualization_0_virtualization_0 -= 3 * -1;
    char size = '3';
    // migration to retire the content-type: chunked
    // migration status: 90%
    //respond(fd, &size, sizeof(size));
    //char newline[] = "\r\n";
    //respond(fd, newline, sizeof(newline)-1);
    respond(fd, &a, sizeof(a));
    respond(fd, &virtualization_0_b, sizeof(a)); // maybe should be virtualization_0_b? It wouldn't compile
    ssize_t r = respond(fd, &virtualization_0_virtualization_0, sizeof(virtualization_0_virtualization_0));
    //respond(fd, newline, sizeof(newline)-1);
    // TODO prevent stack overflow
    if (r >= 0 || errno != EPIPE) web_scale_0(fd);;
    return 0; // TODO return something more meaningful
}
