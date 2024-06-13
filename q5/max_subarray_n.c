#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h> // Include this header for INT_MIN

// Function to find the maximum subarray sum
int maxSubArraySum(int nums[], int size) {
    int maxSum = INT_MIN; // Initialize maxSum to the smallest possible integer
    int currSum = 0; // Initialize currSum to 0
    for (int i = 0; i < size; ++i) { // Loop through the array
        if (nums[i] > currSum + nums[i]) { // If the current element is greater than the current sum plus the current element
            currSum = nums[i]; // Set the current sum to the current element
        } else {
            currSum += nums[i]; // Otherwise, add the current element to the current sum
        }

        if (maxSum < currSum) { // If the current sum is greater than the max sum
            maxSum = currSum; // Update the max sum
        }
    }
    return maxSum; // Return the maximum subarray sum
}

// Function to generate random numbers, run the algorithm, and measure time
void run(int seed, int size) {
    /* Intializes random number generator */
    srand(seed); 
    int *nums = (int*)malloc(size * sizeof(int)); // Allocate memory for the array
    if (nums == NULL) {
        fprintf(stderr, "malloc failed.\n"); 
        return; // Return from the function
    }
    for (int i = 0; i < size; ++i) { // Loop through the array
        nums[i] = rand() % 100 - 25; // Generate random numbers between -25 and 74
    }

    clock_t start = clock(); // Get the starting time
    int maxSum = maxSubArraySum(nums, size); // Find the maximum subarray sum
    clock_t end = clock(); // Get the ending time
    double elapsedTime = (double)(end - start) / CLOCKS_PER_SEC; // Calculate the elapsed time

    printf("Maximum sub array sum (O(n)): %d\n", maxSum); // Print the maximum subarray sum
    printf("Time taken: %.6f seconds\n", elapsedTime); // Print the elapsed time

    free(nums); // Free the memory allocated for the array
}

int main(int argc, char* argv[]) {
    if (argc != 3) { // Check if the number of command-line arguments is incorrect
        fprintf(stderr, "Usage: %s <seed> <size>\n", argv[0]); 
        return 1; 
    }

    int seed = atoi(argv[1]); // Convert the seed from a string to an integer
    int size = atoi(argv[2]);

    run(seed, size); // Run the algorithm with the provided seed and size

    return 0; 
}
