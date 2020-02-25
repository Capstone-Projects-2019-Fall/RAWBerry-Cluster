//
// Created by Christian Lomboy on 2/24/20.
//

#ifndef GPR_CONVERT_H
#define GPR_CONVERT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <assert.h>
#include <dirent.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>


#include "gpr.h"
#include "gpr_allocator.h"
#include "gpr_buffer.h"
//#include "../../lib/vc5_encoder/vc5_encoder.h"
#include "vc5_encoder.h"
#include "timer.h"
#include "config.h"

void convert(char *path_in, char *path_out);

#endif //GPR_CONVERT_H
