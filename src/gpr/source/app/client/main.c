//
// Created by Christian Lomboy on 2/23/20.
//

#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

int main() {

    // create a socket
    int network_socket;
    network_socket = socket(AF_INET, SOCK_STREAM, 0);

    // specify an address for the socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // connect returns an integer
    int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));

    if (connection_status == -1) {
        printf("Error making connection to remote socket \n\n");
    }

    // read picture size
    printf("Reading picture size...\n");
    int size;
    read(network_socket, &size, sizeof(int));
    printf("%i", size);
    printf(" bytes\n");

    // read picture byte array
    printf("Reading picture byte array...\n");
    char p_array[size];
    read(network_socket, p_array, size);

    // convert it back into a pic
    printf("Converting byte array to DNG...\n");
    FILE *image;
    image = fopen("out.DNG", "w");
    fwrite(p_array, 1, sizeof(p_array), image);
    fclose(image);


    // and then close the socket
    close(network_socket);

    return 0;
}
