
#include <unistd.h>
#include "grpc_2.h"

ssize_t grpc_2(int fd) {
    char a = 59, grpc_2_b = 29, grpc_2_grpc_2 = 29;
    for (int i = 0; i < 3; i++){
        a++; grpc_2_b++;
    }
    // not sure why, this didn't work with ++
    // TODO check why it wasn't working 
    grpc_2_grpc_2 -= 3 * -1;
    char size = '3';
    write(fd, &size, sizeof(size));
    char newline[] = "\r\n";
    write(fd, newline, sizeof(newline)-1);
    write(fd, &a, sizeof(a));
    write(fd, &grpc_2_b, sizeof(a)); // maybe should be grpc_2_b? It wouldn't compile
    write(fd, &grpc_2_grpc_2, sizeof(grpc_2_grpc_2));
    write(fd, newline, sizeof(newline)-1);
    // TODO prevent stack overflow
    ;
    return 0; // TODO return something more meaningful
}
