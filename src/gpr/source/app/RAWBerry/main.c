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

bool verbose;


//argp argument parser documentation
//*************************************************************************
static char doc[] = "RAWBerry Cluster -- a RAW video compression tool";
static char args_doc[] = "<OPTIONS>";
static struct argp_option options[] = {
	{"output-dir", 'o', "DIR", 0,
		"Directory to send output frames to, disables rtsp"},
	{"in-dir", 'i', "DIR", 0,
		"Directory to read files from"},
	{"no-rtsp", 'R', 0, 0, "Forces write to output-dir instead of streaming"},
	{"rstp-path", 'r', "FILE", 0, "path to rtsp binary"},
	{"verbose", 'v', 0, 0, "Be verbose"},
	{"quiet", 'q', 0, 0, "disable verbose"},
	{"log-dir", 'l', "DIR", 0, "Directory to write logs to"},
	{ 0 },
};
struct cluster_args cargs = {
	.in_dir = "./CDNG",
	.out_dir = "./out",
	.rtsp_loc = "../rtsp/rtsp",
	.log_dir = "./log",
	.use_rtsp = 1,
	.verbose = true,
};


static error_t parse_opt(int key, char *arg, struct argp_state *state)
{
	switch(key){
		case 'o':
			cargs.use_rtsp = 0;
			cargs.out_dir = arg;
			break;
		case 'i':
			cargs.in_dir = arg;
			break;
		case 'R':
			cargs.use_rtsp = 0;
			break;
		case 'r':
			cargs.out_dir = arg;
			break;
		case 'v':
			cargs.verbose = true;
			break;
		case 'q':
			cargs.verbose = false;
			break;
		case 'l':
			cargs.log_dir = arg;
			break;
		case ARGP_KEY_END:
			break;
		default:
			return ARGP_ERR_UNKNOWN;
	}
	return 0;
}

static struct argp argp = { options, parse_opt, args_doc, doc};
void fire(struct cluster_args * payload);

int main(int argc, char **argv)
{
	argp_parse(&argp, argc, argv, 0, 0, NULL);
	verbose =cargs.verbose;
	init_mpi(argc, argv);
	fire(&cargs);
	
	exit_mpi();
	return  0;
}

//send buffer and datasource to cluster
void fire(struct cluster_args * payload){

    int cluster_status;//number 

    if((cluster_status = cluster(payload)) != 0){
        exit(cluster_status);//terminate - cluster prints error desc., exit with error status
    }
}
