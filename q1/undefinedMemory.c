#include <stdio.h>
#include <stdlib.h>

int main() {
    // Pointer to an invalid memory address
    int *ptr = (int*)0xdeadbeef;

    // Trying to write to the invalid memory address
    // This will cause a segmentation fault
    *ptr = 68;

    return 0;
}
