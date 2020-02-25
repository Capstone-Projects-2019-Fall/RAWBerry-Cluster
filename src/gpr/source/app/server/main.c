//
// Created by Christian Lomboy on 2/24/20.
//

#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

#include <strings.h>

#include "convert.h"

int create_client_socket(int port, const int* s_sock) {

    // define the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // bind the socket to our specified IP and port
    bind(*s_sock, (struct sockaddr *) &server_address, sizeof(server_address));

    listen(*s_sock, 5);

    int client_socket;
    client_socket = accept(*s_sock, NULL, NULL);

    return client_socket;
}

// TODO modify send_image to read in directories!! And send multiple images

int send_image(char *fname) {

    // TODO handle file compression here

    // create the server socket
    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    int client_socket = create_client_socket(9002, &server_socket);

    // get picture size
    printf("Getting picture size...\n");
    FILE *picture;
    picture = fopen(fname, "r");
    int size;
    fseek(picture, 0, SEEK_END);
    size = ftell(picture);
    fseek(picture, 0, SEEK_SET);

    // send picture size
    printf("Sending picture size...\n");
    printf("%i", size);
    printf(" bytes\n");
    write(client_socket, &size, sizeof(size));

    // send picture as byte array
    printf("Sending picture as byte array...");
    char send_buffer[size];
    while (!feof(picture)) {
        fread(send_buffer, 1, sizeof(send_buffer), picture);
        write(client_socket, send_buffer, sizeof(send_buffer));
        bzero(send_buffer, sizeof(send_buffer));
    }

    // close the socket
    close(server_socket);

    return 0;
}

int main(int argc, char *argv[]) {
    send_image(argv[1]);
    return 0;
}