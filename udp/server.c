#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main()
{
    struct sockaddr_in server, client;
    char buf[256];
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(9999);
    server.sin_family = AF_INET;

    // socket登録
    bind(sock, (struct sockaddr *)&server, sizeof(server));

    for (;;) {
        int len = sizeof(client);
        ssize_t recv_len = recvfrom(sock, buf, sizeof(buf) - 1, 0, (struct sockaddr *)&client, &len);

        if (recv_len >= 0) {
            buf[recv_len] = '\0';  // NULL終端
            printf("%s\n", buf);
        }
    }

    close(sock);

    return 0;
}