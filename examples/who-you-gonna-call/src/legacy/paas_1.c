
#include "../respond.h"
#include "pivot_1.h"
#include <errno.h>

ssize_t paas_1(int fd) {
    char a = 96, paas_1_b = 111, paas_1_paas_1 = 118;
    for (int i = 0; i < 3; i++){
        a++; paas_1_b++;
    }
    // not sure why, this didn't work with ++
    // TODO check why it wasn't working 
    paas_1_paas_1 -= 3 * -1;
    char size = '3';
    // migration to retire the content-type: chunked
    // migration status: 90%
    //respond(fd, &size, sizeof(size));
    //char newline[] = "\r\n";
    //respond(fd, newline, sizeof(newline)-1);
    respond(fd, &a, sizeof(a));
    respond(fd, &paas_1_b, sizeof(a)); // maybe should be paas_1_b? It wouldn't compile
    ssize_t r = respond(fd, &paas_1_paas_1, sizeof(paas_1_paas_1));
    //respond(fd, newline, sizeof(newline)-1);
    // TODO prevent stack overflow
    if (r >= 0 || errno != EPIPE) pivot_1(fd);;
    return 0; // TODO return something more meaningful
}
