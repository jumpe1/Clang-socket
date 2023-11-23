#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

int main()
{
    struct sockaddr_in server;
    char buf[256];

    // AF_INET: IP v4
    // SOCK_STREAM: TCP
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(9999);
    server.sin_family = AF_INET;

    // 3 way handshakeを行う
    connect(sock, (struct sockaddr *)&server, sizeof(server));

    strcpy(buf, "hello");
    send(sock, buf, strlen(buf), 0);

    close(sock);

    return 0;
}