#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <stdlib.h>

#define BUFSIZE 4 // Max length of buffer

int random_general(const int lower, const int upper)
{
    return rand() % (upper - lower + 1) + lower;
}

int main(int argc, char *argv[], char *env[])
{
    srand(time(NULL));
    // SZERVER
    // 1-100 random szam
    if (argc == 2) // klienskent mukodik, kap egy ipcimet ahova küldi
    {
        /********************** Declarations ************************/
        int s;                     // socket ID
        unsigned int server_size;  // length of the sockaddr_in server
        char on = 1;               // sockopt option
        int buffer = 0;            // datagram buffer area
        struct sockaddr_in server; // address of server

        /********************** Initialization **********************/
        server.sin_family = AF_INET;
        server.sin_addr.s_addr = inet_addr(argc == 1 ? "127.0.0.1" : argv[1]);
        server.sin_port = htons(5555);
        server_size = sizeof server;

        /********************** Creating socket *********************/
        s = socket(AF_INET, SOCK_DGRAM, 0);
        setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &on, sizeof on);
        setsockopt(s, SOL_SOCKET, SO_KEEPALIVE, &on, sizeof on);

        while (1)
        {
            /********************** Sending data ************************/
            // printf(" Message to send: ");
            fscanf(stdin, "%d", &buffer);
            sendto(s, &buffer, BUFSIZE, 0, (struct sockaddr *)&server, server_size);
            // printf(" Message have been sent to server.\n");

            /********************** Receive data ************************/
            int tmp_buffer = 0;
            recvfrom(s, &tmp_buffer, BUFSIZE, 0, (struct sockaddr *)&server, &server_size);
            // printf("%d\n", tmp_buffer);
            // printf(" Server's acknowledgement:\n  %d\n", tmp_buffer);
            if (tmp_buffer == 0)
            {
                printf("Nyertel");
                return 0;
            }
            else if (tmp_buffer == -1)
            {
                printf("A keresett szam, az elkuldott szamtol nagyobb\n");
            }
            else
            {
                printf("A keresett szam, az elkuldott szamtol kisebb\n");
            }

            /********************** Closing *****************************/
        }
        close(s);
    }
    else
    {
        /********************** Declarations ************************/
        int s;                     // socket ID
        char on = 1;               // sockopt option
        int buffer = 0;            // datagram buffer area
        unsigned int client_size;  // length of the sockaddr_in client
        struct sockaddr_in server; // address of server
        struct sockaddr_in client; // address of client

        /********************** Initialization **********************/
        server.sin_family = AF_INET;
        server.sin_addr.s_addr = INADDR_ANY;
        server.sin_port = htons(5555);

        /********************** Creating socket *********************/
        s = socket(AF_INET, SOCK_DGRAM, 0);
        setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &on, sizeof on);
        setsockopt(s, SOL_SOCKET, SO_KEEPALIVE, &on, sizeof on);

        /********************** Binding socket **********************/
        bind(s, (struct sockaddr *)&server, sizeof server);
        int Generalt_random = random_general(0, 100);
        while (1)
        { // Continuous server operation

            /********************** Receive data ************************/
            printf("\n Varom a szamot \n");
            recvfrom(s, &buffer, BUFSIZE, 0, (struct sockaddr *)&client, &client_size);
            printf(" A kapott szam: \n  %d", buffer);

            /********************** Sending data ************************/
            int tmp_buffer = 0;
            if (Generalt_random == buffer)
            {
                tmp_buffer = 0;
                Generalt_random = random_general(0, 100);
            }
            else if (buffer < Generalt_random)
            {
                tmp_buffer = -1;
            }
            else
            {
                tmp_buffer = 1;
            }
            sendto(s, &tmp_buffer, BUFSIZE, 0, (struct sockaddr *)&client, client_size);
            printf("A kitalalando szam: %d volt", Generalt_random);
        }

        /*********************** Closing ****************************/
        close(s);
    }
}