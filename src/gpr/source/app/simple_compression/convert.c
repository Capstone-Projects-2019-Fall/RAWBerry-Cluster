//
// Created by Christian Lomboy on 2/24/20.
//

#include "convert.h"


void convert(char *path_in, char *path_out) {

    // Allocate a buffer to read into
    gpr_allocator a;

    // for now use malloc, eventually use buffer allocators (?)
    a.Alloc = malloc;
    a.Free = free;

    // Struct for image parameters (input width, height, fast encoding, preview image, etc.)
    gpr_parameters params;
    // defaults: enable preview - true, compute md5sum - false, fast encoding - false, etc.
    gpr_parameters_set_defaults(&params);

    // disabling preview and enabling fast encoding reduces file size and compression time
    // SDK DOES read this from DNG input - tested with debugger - but there is another factor affecting the output
    params.tuning_info.pixel_format = PIXEL_FORMAT_GBRG_12; // GBRG 12bit pixels packed into 16bits

    // create gpr_buffer struct
    gpr_buffer input_buffer = {NULL, 0};

    // Use routine in gpr libraries to set struct param sizes automatically (buffer)
    if (read_from_file(&input_buffer, path_in, a.Alloc, a.Free) != 0) {
        fprintf(stderr, "Error reading %s\n", path_in);
        exit(-1);
    }

    // Now we have an image open, read parameters of DNG file into struct
    gpr_parse_metadata(&a, &input_buffer, &params);
    // make an output buffer
    gpr_buffer outb = {NULL, 0};

    // Do the thing... - notice params are detected from picture input (set breakpoint)
    gpr_convert_dng_to_gpr(&a, &params, &input_buffer, &outb);

    FILE *f = fopen(path_out, "wb");
    if (fwrite(outb.buffer, 1, outb.size, f) != outb.size) {
        perror("Error");
        fprintf(stderr, "Could not write to %s\n", path_out);
    }
    fflush(f);
    fclose(f);
    free(input_buffer.buffer);
    free(outb.buffer);

}

void read_convert_dir(char *dirin, char *dirout) {

    // structure describing an open directory.
    DIR *dir;
    // returns handle to the directory opened - to be used with readdir()
    dir = opendir(dirin);

    // used to return information about directory entries
    struct dirent *ent;

    // each time readdir() is called with the dir handle, it returns the filename of the next file in the directory
    while ((ent = readdir(dir))) {
        if (*(ent->d_name) == '.') {
            // Force next iteration - filters out current dir and parent dir results (hidden)
            continue;
        }

        // allocate space for path string
        char *fullpath = malloc(strlen(dirin)
                                + strlen(ent->d_name) + 2);
        char *out = malloc(strlen(dirout) + strlen(ent->d_name) + 2);
        if (!fullpath || !out) {
            exit(5);
            /* Uh We Might be F****d here? Whatever */
        }
        sprintf(fullpath, "%s/%s", dirin, ent->d_name);
        sprintf(out, "%s/%s", dirout, ent->d_name);
        convert(fullpath, out);
    }
}