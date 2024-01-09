#include <sys/socket.h> // For socket functions
#include <netinet/in.h> // For sockaddr_in
#include <arpa/inet.h> // For inet_pton
#include <cstdlib> // For exit() and EXIT_FAILURE
#include <iostream> // For cout
#include <unistd.h> // For read

int main(int ac, char **av)
{
    // Create a socket (IPv4, TCP)
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        std::cout << "Failed to create socket. errno: " << errno << std::endl;
        exit(EXIT_FAILURE);
    }

    // Specify an address for the socket
    sockaddr_in sockaddr;
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(8080); // Use the same port as the server
    if (inet_pton(AF_INET, "127.0.0.1", &sockaddr.sin_addr) <= 0) {
        std::cout << "Invalid address/ Address not supported. errno: " << errno << std::endl;
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&sockaddr, sizeof(sockaddr)) < 0) {
        std::cout << "Connection Failed. errno: " << errno << std::endl;
        exit(EXIT_FAILURE);
    }

    // Send a message to the server
    std::string message = av[1];
    send(sockfd, message.c_str(), message.size(), 0);
    std::cout << "Message sent to server." << std::endl;

    // Read the server's response
    char buffer[100] = {0};
    auto bytesRead = read(sockfd, buffer, 100);
    std::cout << "Server's response: " << buffer;

    // Close the socket
    close(sockfd);

    return 0;
}
