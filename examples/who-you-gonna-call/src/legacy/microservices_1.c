
#include <unistd.h>
#include "monolith_1.h"

ssize_t microservices_1(int fd) {
    char a = 98, microservices_1_b = 113, microservices_1_microservices_1 = 98;
    for (int i = 0; i < 3; i++){
        a++; microservices_1_b++;
    }
    // not sure why, this didn't work with ++
    // TODO check why it wasn't working 
    microservices_1_microservices_1 -= 3 * -1;
    char size = '3';
    write(fd, &size, sizeof(size));
    char newline[] = "\r\n";
    write(fd, newline, sizeof(newline)-1);
    write(fd, &a, sizeof(a));
    write(fd, &microservices_1_b, sizeof(a)); // maybe should be microservices_1_b? It wouldn't compile
    write(fd, &microservices_1_microservices_1, sizeof(microservices_1_microservices_1));
    write(fd, newline, sizeof(newline)-1);
    // TODO prevent stack overflow
    monolith_1(fd);
    return 0; // TODO return something more meaningful
}
