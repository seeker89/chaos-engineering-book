// close, write, usleep
#include <unistd.h>
// socket, accept, socklen_t
#include <arpa/inet.h>
#include <err.h>

#include "./legacy/writer.h"

// using chunked encoding because of bug 5123
char header[] = "HTTP/1.1 200 OK\r\n"
"Content-Type: text/html; charset=UTF-8\r\n"
"Server: Pretty Legacy\r\n"
"Transfer-Encoding: chunked\r\n"
"Connection: close\r\n"
"\r\n";

char footer[] =
"0\r\n"
"\r\n";

int main()
{
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
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    // bind and listen
    // http://man7.org/linux/man-pages/man2/accept.2.html
    int res = bind(sock, (struct sockaddr *) &address, sizeof(address));
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
            write(client_fd, header, sizeof(header) - 1);
            write_content(client_fd);
            write(client_fd, footer, sizeof(footer) - 1);
            // simulate some more work by sleeping for 5ms
            usleep(5*1000);
            close(client_fd);
        }
    }
}
