#include <iostream>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>

using namespace std;

int main() {
    cout << "exe1 START" << endl;
    auto socket_path = "/tmp/my_socket.sock";
    unlink(socket_path);
    int sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sockfd == -1)
        return 1;
    sockaddr_un addr;
    memset(&addr, 0, sizeof(sockaddr_un));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, socket_path, sizeof(addr.sun_path) - 1);
    if (::bind(sockfd, (sockaddr*)&addr, sizeof(sockaddr_un)) == -1)
        return 2;
    if (listen(sockfd, SOMAXCONN) == -1)
        return 3;
    int clientSock = accept(sockfd, nullptr, nullptr);
    if (clientSock == -1)
        return 4;
    char buffer[1024];
    auto bytesRead = read(clientSock, buffer, sizeof(buffer));
    if (bytesRead == -1)
        return 5;
    cout << "Received msg: " << buffer << endl;
    close(sockfd);
    return 0;
}