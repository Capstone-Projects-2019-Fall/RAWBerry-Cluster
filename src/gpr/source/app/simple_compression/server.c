//
// Created by Christian Lomboy on 2/26/20.
//

#include <limits.h>
#include "server.h"
#include "convert.h"

int create_client_socket(int port, const int *s_sock) {

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

// TODO modify send_dir to read in directories!! And send multiple images


int send_file(char *fpath, int *socket) {

    // get picture size
    printf("Getting picture size...\n");
    FILE *picture;
    picture = fopen(fpath, "r");
    int size;
    fseek(picture, 0, SEEK_END);
    size = ftell(picture);
    fseek(picture, 0, SEEK_SET);

    // send picture size
    printf("Sending picture size...\n");
    printf("%i", size);
    printf(" bytes\n");
    write(*socket, &size, sizeof(size));

    // send picture as byte array
    printf("Sending picture as byte array...");
    char send_buffer[size];
    while (!feof(picture)) {
        fread(send_buffer, 1, sizeof(send_buffer), picture);
        write(*socket, send_buffer, sizeof(send_buffer));
        bzero(send_buffer, sizeof(send_buffer));
    }

    return 0;
}


int send_dir(char *dirin, char *dirsend) {

    // TODO handle file compression here
    read_convert_dir(dirin, dirsend);

    // structure describing an open directory.
    DIR *dir;
    // returns handle to the directory opened - to be used with readdir()
    dir = opendir(dirsend);

    // used to return information about directory entries
    struct dirent *ent;

    // create the server socket
    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    int client_socket = create_client_socket(9002, &server_socket);

    // each time readdir() is called with the dir handle, it returns the filename of the next file in the directory
    while ((ent = readdir(dir))) {

        if (*(ent->d_name) == '.') {
            // Force next iteration - filters out current dir and parent dir results (hidden)
            continue;
        }
        char buf[PATH_MAX + 1];

        strcat(dirsend, "/");
        strcat(dirsend, ent->d_name);
        printf("%s", dirsend);
        send_file(dirsend, &client_socket);

    }

    // close the socket
    close(server_socket);

    return 0;
}
