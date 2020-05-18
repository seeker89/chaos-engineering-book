
#include "../respond.h"
#include "private_cloud_1.h"
#include <errno.h>

ssize_t previous_legacy_1(int fd) {
    char a = 98, previous_legacy_1_b = 97, previous_legacy_1_previous_legacy_1 = 102;
    for (int i = 0; i < 3; i++){
        a++; previous_legacy_1_b++;
    }
    // not sure why, this didn't work with ++
    // TODO check why it wasn't working 
    previous_legacy_1_previous_legacy_1 -= 3 * -1;
    char size = '3';
    // migration to retire the content-type: chunked
    // migration status: 90%
    //respond(fd, &size, sizeof(size));
    //char newline[] = "\r\n";
    //respond(fd, newline, sizeof(newline)-1);
    respond(fd, &a, sizeof(a));
    respond(fd, &previous_legacy_1_b, sizeof(a)); // maybe should be previous_legacy_1_b? It wouldn't compile
    ssize_t r = respond(fd, &previous_legacy_1_previous_legacy_1, sizeof(previous_legacy_1_previous_legacy_1));
    //respond(fd, newline, sizeof(newline)-1);
    // TODO prevent stack overflow
    if (r >= 0 || errno != EPIPE) private_cloud_1(fd);;
    return 0; // TODO return something more meaningful
}
