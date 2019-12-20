#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int wait = 1;
    int block_size = 33554432; // 32Mb
    char * allocated_block;
    
    while (1) {

        if ((allocated_block = (char*)malloc(block_size)) == NULL) {
            printf("Couldn't allocate!\n");
        } else {
            // write data to our newly allocated memory to actually claim it
            for (int i=0; i < block_size; i++){
                *(allocated_block + i) = 'Y';
            }
        }
    
        printf("Sleeping %ds\n", wait);
        sleep(wait); 
    }

    return 0;
}