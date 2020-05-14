
#include <unistd.h>
#include "ai_2.h"

ssize_t agile_2(int fd) {
    char a = 96, agile_2_b = 113, agile_2_agile_2 = 114;
    for (int i = 0; i < 3; i++){
        a++; agile_2_b++;
    }
    // not sure why, this didn't work with ++
    // TODO check why it wasn't working 
    agile_2_agile_2 -= 3 * -1;
    char size = '3';
    write(fd, &size, sizeof(size));
    char newline[] = "\r\n";
    write(fd, newline, sizeof(newline)-1);
    write(fd, &a, sizeof(a));
    write(fd, &agile_2_b, sizeof(a)); // maybe should be agile_2_b? It wouldn't compile
    write(fd, &agile_2_agile_2, sizeof(agile_2_agile_2));
    write(fd, newline, sizeof(newline)-1);
    // TODO prevent stack overflow
    ai_2(fd);
    return 0; // TODO return something more meaningful
}
