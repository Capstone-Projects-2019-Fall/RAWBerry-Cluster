/*
File: main.c
Author: Patrick Pettus (tuf50784@temple.edu), 10/19/19

Desc: file containing main function, as well as functions to initialize components and read data into Cluster
*/

#include "cluster.h"
#include "input.h"
#include <argp.h>
#include <sys/types.h> 
#include <unistd.h> 


#define DIR_LENGTH 64


//argp argument parser documentation
//*************************************************************************
//static char doc[] = "RAWBerry Cluster -- a RAW video compression tool";
//static char args_doc[] = "<DIRECTORY> <CLUSTER_CONFIG>";
//static struct argp_option options[] = {
    //here we can choose what options to encore for cluster
    //some of these may be passed to cluster via payload.ops
//};
//struct arguments {
    //argument entities
  //  char *args[2]; //these are our DIRECTORY and CONFIG arguments
    //other variables can be added here for more args, options, etc
//};
//static struct argp argp = { options, parse_opt, args_doc, doc};//argp argument parser struct
//**************************************************************************

void initialize();
void readDNG(char* dir, buf_handle_t buf);
void fire(struct cluster_args * payload);


int main(int argc, char **argv){


    //char dir[DIR_LENGTH];//string of directory to ingest to buffer
    long opts;//options parameter for cluster

    gpr_buffer *buffer = malloc(BUFFER_SIZE * sizeof(gpr_buffer));//define and allocate memory for input-buffer
    buf_handle_t buf = buf_init(buffer, BUFFER_SIZE);//instantiate buffer
    
//    struct arguments arguments;//argp parser arguments
    struct cluster_args * payload;//payload gets populated when command line arguments are parsed


 //   argp_parse(&argp, argc, argv, 0, 0, &arguments);//parse arguments
 //   dir = arguments.args[0];//first argument is directory to be read to buffer

    //initialize();//initialize cluster components
    char dir[] = "/CDNG";
    //***NOTE*** left this unthreaded for now to work out integration data path
    
    int pid = fork();

	if ( pid == 0 ) {
		execvp( "../rtsp/rtsp", "");
	}
    readDNG(dir, buf);//read contents of dir to buf

    //payload->source = buf;//populate cluster_args struct source
    //payload->compopts = opts;//populate cluster_args struct opts

    //fire(payload);//sends cluster_arguments (source and buffer) to cluster



    //free data structures
    free(buffer);

}

//init cluster's mpi procedure
void initialize(){

    int cluster_mpi_status;//status of mpi initialization init_mpi(..)

    //initialize cluster components
    if((cluster_mpi_status = init_mpi()) != 0){
        exit(cluster_mpi_status);//terminate - cluster prints error desc., exit with error status
    }
}

//read contents of DIR to buffer BUF
void readDNG(char * dir, buf_handle_t buf){

    int read_status;//status of readFiles(..) function

    //read data to buffer
    if((read_status = readFiles(dir, buf)) != 0){
        exit(read_status);//terminate - exit with error status
    }
}

//send buffer and datasource to cluster
void fire(struct cluster_args * payload){

    int cluster_status;//number 

    //pass buffer handle of datastream and options long to cluster for execution
    if((cluster_status = cluster(payload)) != 0){
        exit(cluster_status);//terminate - cluster prints error desc., exit with error status
    }
}
