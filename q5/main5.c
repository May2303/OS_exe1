#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "q5.h"

void run_algorithms(int arr[], int size) {
    clock_t start, end;
    double elapsedTime;

    start = clock();
    int maxSum = maxSubArraySum(arr, size);
    end = clock();
    elapsedTime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Maximum subarray sum (O(n)): %d\n", maxSum);
    printf("Time taken: %.6f seconds\n\n", elapsedTime);

    start = clock();
    maxSum = maxSubArraySum2(arr, size);
    end = clock();
    elapsedTime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Maximum subarray sum (O(n^2)): %d\n", maxSum);
    printf("Time taken: %.6f seconds\n\n", elapsedTime);

    start = clock();
    maxSum = maxSubArraySum3(arr, size);
    end = clock();
    elapsedTime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Maximum subarray sum (O(n^3)): %d\n", maxSum);
    printf("Time taken: %.6f seconds\n", elapsedTime);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <seed> <size>\n", argv[0]);
        return 1;
    }

    unsigned int seed = (unsigned int)atoi(argv[1]);
    int size = atoi(argv[2]);

    if (size != 100 && size != 1000 && size != 10000) {
        fprintf(stderr, "Size must be one of the following: 100, 1000, 10000\n");
        return 1;
    }

    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "malloc failed.\n");
        return 1;
    }

    generate_random_array(arr, size, seed);
    run_algorithms(arr, size);

    free(arr);
    return 0;
}
