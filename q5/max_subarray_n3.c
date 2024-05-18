#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int maxSubArraySum3(int nums[], int size) {
    int maxSum = INT_MIN;
    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            int currSum = 0;
            for (int k = i; k <= j; ++k) {
                currSum += nums[k];
            }
            maxSum = (maxSum > currSum) ? maxSum : currSum;
        }
    }
    return maxSum;
}

void run3(int seed, int size) {
    srand(seed);
    int *nums = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) {
        nums[i] = rand() % 100 - 25;
    }

    clock_t start = clock();
    int maxSum = maxSubArraySum3(nums, size);
    clock_t end = clock();
    double elapsedTime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Maximum subarray sum (O(n^3)): %d\n", maxSum);
    printf("Time taken: %.6f seconds\n", elapsedTime);

    free(nums);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <seed> <size>\n", argv[0]);
        return 1;
    }

    int seed = atoi(argv[1]);
    int size = atoi(argv[2]);

    run3(seed, size);

    return 0;
}