#include <stdio.h>
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
    // SOCK_DGRAM: UDP
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(9999);
    server.sin_family = AF_INET;

    strcpy(buf, "hello");;
    sendto(sock, buf, strlen(buf), 0, (struct sockaddr *)&server, sizeof(server));

    close(sock);

    return 0;
}