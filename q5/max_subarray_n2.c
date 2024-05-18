#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h> // Include this header for INT_MIN

int maxSubArraySum2(int nums[], int size) {
    int maxSum = INT_MIN;
    for (int i = 0; i < size; ++i) {
        int currSum = 0;
        for (int j = i; j < size; ++j) {
            currSum += nums[j];
            maxSum = (maxSum > currSum) ? maxSum : currSum;
        }
    }
    return maxSum;
}

void run2(int seed, int size) {
    srand(seed);
    int *nums = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) {
        nums[i] = rand() % 100 - 25;
    }

    clock_t start = clock();
    int maxSum = maxSubArraySum2(nums, size);
    clock_t end = clock();
    double elapsedTime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Maximum sub array sum (O(n^2)): %d\n", maxSum);
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

    run2(seed, size);

    return 0;
}
