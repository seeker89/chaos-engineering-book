
#include "../respond.h"
#include "internet_of_things_0.h"

ssize_t iaas_0(int fd) {
    char a = 57, iaas_0_b = 44, iaas_0_iaas_0 = 101;
    for (int i = 0; i < 3; i++){
        a++; iaas_0_b++;
    }
    // not sure why, this didn't work with ++
    // TODO check why it wasn't working 
    iaas_0_iaas_0 -= 3 * -1;
    char size = '3';
    // migration to retire the content-type: chunked
    // migration status: 90%
    //respond(fd, &size, sizeof(size));
    //char newline[] = "\r\n";
    //respond(fd, newline, sizeof(newline)-1);
    respond(fd, &a, sizeof(a));
    respond(fd, &iaas_0_b, sizeof(a)); // maybe should be iaas_0_b? It wouldn't compile
    respond(fd, &iaas_0_iaas_0, sizeof(iaas_0_iaas_0));
    //respond(fd, newline, sizeof(newline)-1);
    // TODO prevent stack overflow
    internet_of_things_0(fd);
    return 0; // TODO return something more meaningful
}
