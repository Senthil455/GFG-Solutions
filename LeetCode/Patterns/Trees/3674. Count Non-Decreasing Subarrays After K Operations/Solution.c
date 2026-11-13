#include <stdlib.h>
#include <string.h>

long long countNonDecreasingSubarrays(int* nums, int n, long long k) {
    // Reverse array in-place
    for (int i = 0; i < n / 2; i++) {
        int t = nums[i];
        nums[i] = nums[n - 1 - i];
        nums[n - 1 - i] = t;
    }

    long long result = 0;
    int left = 0;

    // Simple deque using array
    int *mono = malloc(sizeof(int) * n);
    int front = 0, back = 0;

    for (int right = 0; right < n; right++) {
        int val = nums[right];

        // Merge smaller plateau values
        while (back > front && nums[mono[back-1]] < val) {
            int r = mono[--back];
            int l = (back == front) ? left - 1 : mono[back-1];
            k -= (long long)(r - l) * (val - nums[r]);
        }

        mono[back++] = right;

        // Shrink window if cost exceeded
        while (k < 0) {
            k += nums[mono[front]] - nums[left];
            if (mono[front] == left) front++;
            left++;
        }

        result += right - left + 1;
    }

    free(mono);
    return result;
}