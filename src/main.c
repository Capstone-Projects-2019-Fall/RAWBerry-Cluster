/*
File: main.c
Author: Patrick Pettus (tuf50784@temple.edu), 10/19/19

Desc: file containing main function, as well as functions to initialize components and read data into Cluster
*/

#include <cluster.h>
#include <input.h>


#define DIR_LENGTH 64


void initialize();
void read(char[] dir, buf_handle_t buf);
void fire(struct cluster_args payload);


int main(int argc, char **argv){


    char dir[DIR_LENGTH];//string of directory to ingest to buffer
    long opts;//options parameter for cluster

    gpr_buffer *buffer = malloc(BUFFER_SIZE * sizeof(gpr_buffer));//define and allocate memory for input-buffer
    buf_handle_t buf = buf_init(buffer, BUFFER_SIZE);//instantiate buffer


    struct cluster_args payload;//payload gets populated when command line arguments are parsed


    //parse arguments



    initialize();//initialize cluster components
    read(dir, buf);//read contents of dir to buf

    payload.source = buf;//populate cluster_args struct source
    payload.compopts = opts;//populate cluster_args struct opts



    fire();



    //free data structures
    free(buffer);

}

void initialize(){

    int cluster_mpi_status;//status of mpi initialization init_mpi(..)

    //initialize cluster components
    if((cluster_mpi_status = init_mpi()) != 0){
        exit(cluster_mpi_status);//terminate - cluster prints error desc., exit with error status
    }
}

void read(char[] dir, buf_handle_t buf){

    int read_status;//status of readFiles(..) function

    //read data to buffer
    if((read_status = readFiles(dir, buf)) != 0){
        exit(read_status);//terminate - exit with error status
    }
}

void fire(struct cluster_args payload){

    int cluster_status;//number 

    //pass buffer handle of datastream and options long to cluster for execution
    if((cluster_status = cluster(payload)) != 0){
        exit(cluster_status);//terminate - cluster prints error desc., exit with error status
    }
}