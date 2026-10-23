int sortPermutation(int* nums, int numsSize) {
    int ans = -1;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != i) {
            if (ans == -1) {
                ans = nums[i];
            } else {
                ans &= nums[i];
            }
        }
    }

    return ans == -1 ? 0 : ans;
}