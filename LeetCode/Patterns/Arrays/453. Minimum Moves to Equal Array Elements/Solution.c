int minMoves(int* nums, int numsSize) {
    long long sum = 0;
    int min_val = nums[0];
    
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        if (nums[i] < min_val) {
            min_val = nums[i];
        }
    }
    
    return (int)(sum - (long long)numsSize * min_val);
}