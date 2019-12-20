#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int wait = 1;
    int block_size = 64*1024*1024;
    int step = 1024*1024;
    char * allocated_block;
    
    while (1) {

        if ((allocated_block = (char*)malloc(block_size)) == NULL) {
            //printf("Couldn't malloc %d!\n", block_size);
            if (block_size > 2*step){
                block_size -= step;
            }
        } else {
            // slowly write data to our newly allocated memory to actually claim it and use some CPU
            for (int i=0; i < block_size; i++){
                *(allocated_block + i) = 'Y';
            }
        }
        sleep(wait); 
    }

    return 0;
}
