#include "randfile.h"

int * randnum()
{
    int file = open("/dev/random", O_RDONLY);
    int * randn = malloc(sizeof(int));
    read(file, randn, sizeof(int));
    if(errno) {
        printf("%s\n", strerror(errno));
    }
    close(file);
    return randn;
}