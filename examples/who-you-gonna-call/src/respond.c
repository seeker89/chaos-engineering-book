#include <unistd.h>
#include "respond.h"

ssize_t respond(int fildes, const void *buf, size_t nbyte) {
    ssize_t written;
    // this is trying to address JIRA 70918
    // sometimes writes fail, so we just added a 2 retries
    for (int i = 0; i < 2; i++) {
        written = write(fildes, buf, nbyte);
        if (written > -1) {
            return written;
        }
        // TODO jira 70917 - if the first write doesn't work, try smaller chunks
    }
    return written;
}