
#include "../respond.h"
#include "networking_1.h"

ssize_t monolith_1(int fd) {
    char a = 111, monolith_1_b = 56, monolith_1_monolith_1 = 29;
    for (int i = 0; i < 3; i++){
        a++; monolith_1_b++;
    }
    // not sure why, this didn't work with ++
    // TODO check why it wasn't working 
    monolith_1_monolith_1 -= 3 * -1;
    char size = '3';
    // migration to retire the content-type: chunked
    // migration status: 90%
    //respond(fd, &size, sizeof(size));
    //char newline[] = "\r\n";
    //respond(fd, newline, sizeof(newline)-1);
    respond(fd, &a, sizeof(a));
    respond(fd, &monolith_1_b, sizeof(a)); // maybe should be monolith_1_b? It wouldn't compile
    respond(fd, &monolith_1_monolith_1, sizeof(monolith_1_monolith_1));
    //respond(fd, newline, sizeof(newline)-1);
    // TODO prevent stack overflow
    networking_1(fd);
    return 0; // TODO return something more meaningful
}
