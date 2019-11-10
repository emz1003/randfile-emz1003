#include <stdio.h>
#include <stdlib.h>
#include "randfile.h"

int main() {
    int i;
    int * n;
    int arr0[10];
    printf("Generating random numbers:\n");
    for(i = 0; i < 10; i++) {
        arr0[i] = *randnum();
        printf("\trandom %d: %d\n", i, arr0[i]);
    }
    printf("\n");

    /* writing from arr0 to file0 */
    printf("writing from arr0 to file0...\n\n");

    int f0 = open("file0", O_CREAT | O_EXCL | O_WRONLY, 0644);

    if (errno)
    {
        printf("%s\n", strerror(errno));
    }

    write(f0, arr0, sizeof(arr0));

    if (errno)
    {
        printf("%s\n", strerror(errno));
    }

    close(f0);

    /* reading file0 to arr1...*/
    printf("reading file0 to arr1\n\n");

    f0 = open("file0", O_RDONLY);

    int arr1[10];

    if (errno)
    {
        printf("%s\n", strerror(errno));
    }

    read(f0, arr1, sizeof(arr1));

    if (errno)
    {
        printf("%s\n", strerror(errno));
    }

    /* closing file0 */

    close(f0);

    if (errno)
    {
        printf("%s\n", strerror(errno));
    }

    printf("verification printing out arr1:\n");
    for(i = 0; i < 10; i++) {
        printf("\trandom %d: %d\n", i, arr1[i]);
    }

    return 0;
}