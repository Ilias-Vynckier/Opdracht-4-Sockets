#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <netdb.h> // for getnameinfo()

// Usual socket headers
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <arpa/inet.h>

#include <gpiod.h> // gpiod

#define SIZE 1024
#define BACKLOG 10 // Passed to listen()

void report(struct sockaddr_in *serverAddress);
int state[50];

void setHttpHeader(char httpHeader[])
{
    // File object to return
    FILE *htmlData = fopen("../index.html", "r");
    /*char gpio26[50];
    sprintf(gpio26, "<p>gpio26 is %d</p>", gpio());*/

    char line[100];
    char responseData[8000];
    while (fgets(line, 100, htmlData) != 0)
    {
        strcat(responseData, line);
    }
    // char httpHeader[8000] = "HTTP/1.1 200 OK\r\n\n";
    //strcat(responseData, gpio26);
    strcat(httpHeader, responseData);
}

int main(void)
{
    char httpHeader[8000] = "HTTP/1.1 200 OK\r\n\n";

    // Socket setup: creates an endpoint for communication, returns a descriptor
    // -----------------------------------------------------------------------------------------------------------------
    int serverSocket = socket(
        AF_INET,     // Domain: specifies protocol family
        SOCK_STREAM, // Type: specifies communication semantics
        0            // Protocol: 0 because there is a single protocol for the specified family
    );

    // Construct local address structure
    // -----------------------------------------------------------------------------------------------------------------
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8001);
    serverAddress.sin_addr.s_addr = htonl(INADDR_LOOPBACK); //inet_addr("127.0.0.1");

    // Bind socket to local address
    // -----------------------------------------------------------------------------------------------------------------
    // bind() assigns the address specified by serverAddress to the socket
    // referred to by the file descriptor serverSocket.
    bind(
        serverSocket,                      // file descriptor referring to a socket
        (struct sockaddr *)&serverAddress, // Address to be assigned to the socket
        //(struct sockaddr *) 8000,   // Address to be assigned to the socket
        sizeof(serverAddress) // Size (bytes) of the address structure
    );

    // Mark socket to listen for incoming connections
    // -----------------------------------------------------------------------------------------------------------------
    int listening = listen(serverSocket, BACKLOG);
    if (listening < 0)
    {
        printf("Error: The server is not listening.\n");
        return 1;
    }
    report(&serverAddress);    // Custom report function
    setHttpHeader(httpHeader); // Custom function to set header
    int clientSocket;

    // Wait for a connection, create a connected socket if a connection is pending
    // -----------------------------------------------------------------------------------------------------------------
    int i = 0;
    int flag=0;
    while (1)
    {
        clientSocket = accept(serverSocket, NULL, NULL);
        int gpioStateArr[50];
        //gpioStateArr[0]=gpio();
        sprintf(gpioStateArr, "%d", gpio());

        char gpiotemp[500];

        if (flag==3)
        {
            sprintf(gpiotemp, "<p>gpio19 is %d</p><p>gpio26 is %d</p><h1>%d</h1>", state[0], state[1], i);
            i++;
            flag=0;
        }
        flag++;

        strcat(httpHeader, gpiotemp);

        send(clientSocket, httpHeader, sizeof(httpHeader), 0);
        close(clientSocket);
    }
    return 0;
}

void report(struct sockaddr_in *serverAddress)
{
    char hostBuffer[INET6_ADDRSTRLEN];
    char serviceBuffer[NI_MAXSERV]; // defined in `<netdb.h>`
    socklen_t addr_len = sizeof(*serverAddress);
    int err = getnameinfo(
        (struct sockaddr *)serverAddress,
        addr_len,
        hostBuffer,
        sizeof(hostBuffer),
        serviceBuffer,
        sizeof(serviceBuffer),
        NI_NUMERICHOST);
    if (err != 0)
    {
        printf("It's not working!!\n");
    }
    printf("\n\n\tServer listening on http://%s:%s\n", hostBuffer, serviceBuffer);
}

int gpio()
{
    const char *chipname = "gpiochip0";
    struct gpiod_chip *chip;
    struct gpiod_line *gpio26; // GPIO 19
    struct gpiod_line *gpio19; // GPIO 19

    // Open GPIO chip
    chip = gpiod_chip_open_by_name(chipname);

    // Open GPIO lines
    gpio26 = gpiod_chip_get_line(chip, 26);
    gpio19 = gpiod_chip_get_line(chip, 19);

    // Open switch line for input
    gpiod_line_request_output(gpio26, "gpio26", NULL);
    gpiod_line_request_input(gpio19, "gpio26");

    //gpiod_line_set_value(gpio19,1);

    state[0] = gpiod_line_get_value(gpio19);
    state[1] = gpiod_line_get_value(gpio26);

    gpiod_line_release(gpio19);
    gpiod_line_release(gpio26);

    return state;
}
