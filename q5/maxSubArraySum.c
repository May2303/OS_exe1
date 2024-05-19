#include "q5.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

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

void generate_random_array(int arr[], int size, unsigned int seed) {
    srand(seed);
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100 - 25;
    }
}
