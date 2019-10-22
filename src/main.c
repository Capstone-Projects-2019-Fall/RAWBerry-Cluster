/*
File: main.c
Author: Patrick Pettus (tuf50784@temple.edu), 10/19/19

Desc: file containing main function, as well as functions to initialize components and read data into Cluster
*/

#include <cluster.h>
#include <input.h>

#define DIR_LENGTH 64

int main(int argc, char **argv){


    int read_status;//status of readFiles(..) function
    int cluster_mpi_status;//status of mpi initialization init_mpi(..)
    int cluster_status;//number 
    char dir[DIR_LENGTH];//string of directory to ingest to buffer
    long opts;//options parameter for cluster


    gpr_buffer *buffer = malloc(BUFFER_SIZE * sizeof(gpr_buffer));//define and allocate memory for input-buffer
    buf_handle_t buf = buf_init(buffer, BUFFER_SIZE);//instantiate buffer


    struct cluster_args payload;//payload gets populated when command line arguments are parsed


    //parse arguments




    //initialize cluster components
    if((cluster_mpi_status = init_mpi()) != 0){
        exit(cluster_mpi_status);//terminate - cluster prints error desc., exit with error status
    }




    //read data to buffer
    if((read_status = readFiles(dir, buf)) != 0){
        exit(read_status);//terminate - exit with error status
    }
    //set up cluster entry
    payload.source = buf;//populate cluster_args struct source
    payload.compopts = opts;//populate cluster_args struct opts




    //pass buffer handle of datastream and options long to cluster for execution
    if((cluster_status = cluster(payload)) != 0){
        exit(cluster_status);//terminate - cluster prints error desc., exit with error status
    }



    //free data structures
    free(buffer);

}

