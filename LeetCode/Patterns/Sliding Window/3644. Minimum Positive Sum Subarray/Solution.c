int minimumSumSubarray(int* nums, int numsSize, int l, int r) {
    int min = INT_MAX;

    for (int j = l; j <= r; j++) {
        int sum = 0;
        for (int i = 0; i < j; i++)
            sum += nums[i];

        min = (sum > 0) ? (sum > min) ? min : sum : min;

        int temp = sum;
        for (int i = j; i < numsSize; i++) {
            temp += nums[i] - nums[i - j];
            min = (temp > 0) ? (temp > min) ? min : temp : min;
        }
    }
    return (min != INT_MAX) ? min : -1;
}