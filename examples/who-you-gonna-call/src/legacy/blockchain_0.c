
#include <unistd.h>
#include "cloud_0.h"

ssize_t blockchain_0(int fd) {
    char a = 57, blockchain_0_b = 101, blockchain_0_blockchain_0 = 113;
    for (int i = 0; i < 3; i++){
        a++; blockchain_0_b++;
    }
    // not sure why, this didn't work with ++
    // TODO check why it wasn't working 
    blockchain_0_blockchain_0 -= 3 * -1;
    char size = '3';
    write(fd, &size, sizeof(size));
    char newline[] = "\r\n";
    write(fd, newline, sizeof(newline)-1);
    write(fd, &a, sizeof(a));
    write(fd, &blockchain_0_b, sizeof(a)); // maybe should be blockchain_0_b? It wouldn't compile
    write(fd, &blockchain_0_blockchain_0, sizeof(blockchain_0_blockchain_0));
    write(fd, newline, sizeof(newline)-1);
    // TODO prevent stack overflow
    cloud_0(fd);
    return 0; // TODO return something more meaningful
}
