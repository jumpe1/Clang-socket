#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

int main()
{
    struct sockaddr_in server, client;
    char buf[256], snd_buf[256];

    memset(buf, 0, sizeof(buf));
    snprintf(snd_buf, sizeof(snd_buf),
             "HTTP/1.1 200 OK\r\n"
             "Date: Thu, 23 Nov 2023 17:18:34 GMT\r\n"
             "Server: Apache/2.2\r\n"
             "Content-Length: 13\r\n"
             "\r\n"
             "Hello Client\r\n");

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(9999);
    server.sin_family = AF_INET;

    // socket登録
    bind(sock, (struct sockaddr *)&server, sizeof(server));

    listen(sock, 1);

    for (;;) {
        // bindしたsocketに対して接続があるまで待機
        int len = sizeof(client);
        int sock2 = accept(sock, (struct sockaddr *)&client, &len);

        recv(sock2, buf, sizeof(buf), 0);
        send(sock2, snd_buf, strlen(snd_buf), 0);
        printf("%s\n", buf);

        close(sock2);
    }

    close(sock);

    return 0;
}