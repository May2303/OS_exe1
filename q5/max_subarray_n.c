#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h> // Include this header for INT_MIN

int maxSubArraySum(int nums[], int size) {
    int maxSum = INT_MIN;
    int currSum = 0;
    for (int i = 0; i < size; ++i) {
        if (nums[i] > currSum + nums[i]) {
            currSum = nums[i];
        } else {
            currSum += nums[i];
        }

        if (maxSum < currSum) {
            maxSum = currSum;
        }
    }
    return maxSum;
}


void run(int seed, int size) {
    srand(seed);
    int *nums = (int*)malloc(size * sizeof(int));
    if (nums == NULL) {
        fprintf(stderr, "malloc failed.\n");
        return;
    }
    for (int i = 0; i < size; ++i) {
        nums[i] = rand() % 100 - 25;
    }

    clock_t start = clock();
    int maxSum = maxSubArraySum(nums, size);
    clock_t end = clock();
    double elapsedTime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Maximum sub array sum (O(n)): %d\n", maxSum);
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

    run(seed, size);

    return 0;
}