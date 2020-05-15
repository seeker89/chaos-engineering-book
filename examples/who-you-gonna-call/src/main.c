// close, write, usleep
#include <unistd.h>
// socket, accept, socklen_t
#include <arpa/inet.h>
#include <sys/socket.h>
#include <err.h>

#include "./legacy/writer.h"

#define BUFSIZE 2048

// using chunked encoding because of bug 5123
char header[] = "HTTP/1.0 200 OK\r\n"
"Content-Type: text/html; charset=UTF-8\r\n"
"Server: Pretty Legacy\r\n"
"Connection: close\r\n"
"Content-Length: " CTN_LENGTH "\r\n"
"\r\n";

int main()
{
    int res;
    char buf[BUFSIZE];
    // get a socket and configure it
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        err(1, "error opening socket");
    }
    int options = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &options, sizeof(int));

    // build the struct
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_port = htons(8080);

    // bind and listen
    // http://man7.org/linux/man-pages/man2/accept.2.html
    res = bind(sock, (struct sockaddr *) &address, sizeof(address));
    if (res < 0) {
        close(sock);
        err(1, "error binding");
    }
    // http://man7.org/linux/man-pages/man2/listen.2.html
    int arbitrary_queue_len = 1000;
    listen(sock, arbitrary_queue_len);

    // accept some connection
    int client_fd;
    struct sockaddr_in client;
    socklen_t sin_len = sizeof(client);
    while (1) {
        client_fd = accept(sock, (struct sockaddr *) &client, &sin_len);
        if (client_fd != -1) {
            // read the headers
            do {
                res = read(client_fd, buf, BUFSIZE);
                if (res < 0) err(1, "error reading");
            } while (res > 0);
            write(client_fd, header, sizeof(header) - 1);
            write_content(client_fd);
            // simulate some more work by sleeping for 5ms
            usleep(5*1000);
            // don't forget to flush
            fsync(client_fd);
            close(client_fd);
        }
    }
}
