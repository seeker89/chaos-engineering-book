
#include <unistd.h>
#include "data_mining_2.h"

ssize_t crypto_2(int fd) {
    char a = 107, crypto_2_b = 59, crypto_2_crypto_2 = 57;
    for (int i = 0; i < 3; i++){
        a++; crypto_2_b++;
    }
    // not sure why, this didn't work with ++
    // TODO check why it wasn't working 
    crypto_2_crypto_2 -= 3 * -1;
    char size = '3';
    write(fd, &size, sizeof(size));
    char newline[] = "\r\n";
    write(fd, newline, sizeof(newline)-1);
    write(fd, &a, sizeof(a));
    write(fd, &crypto_2_b, sizeof(a)); // maybe should be crypto_2_b? It wouldn't compile
    write(fd, &crypto_2_crypto_2, sizeof(crypto_2_crypto_2));
    write(fd, newline, sizeof(newline)-1);
    // TODO prevent stack overflow
    data_mining_2(fd);
    return 0; // TODO return something more meaningful
}
