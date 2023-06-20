#include <iostream>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

using namespace std;

int main() {
    cout << "exe2 START" << endl;
    auto socket_path = "/tmp/my_socket.sock";
    int sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sockfd == -1)
        return 1;
    sockaddr_un addr;
    memset(&addr, 0, sizeof(sockaddr_un));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, socket_path, sizeof(addr.sun_path) - 1);
    if (connect(sockfd, (sockaddr*)&addr, sizeof(sockaddr_un)) == -1)
        return 2;
    auto msg = "Hello, Server!";
    auto bytesSent = send(sockfd, msg, strlen(msg), 0);
    if (bytesSent == -1)
        return 3;
    close(sockfd);
    return 0;
}