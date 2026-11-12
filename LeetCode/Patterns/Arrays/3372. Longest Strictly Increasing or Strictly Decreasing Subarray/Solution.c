int longestMonotonicSubarray(int* nums, int numsSize) {
    int incLength = 1, decLength = 1, maxLength = 1;

    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i + 1] > nums[i]) {
            incLength++;
            decLength = 1;
        } else if (nums[i + 1] < nums[i]) {
            decLength++;
            incLength = 1;
        } else {
            incLength = 1;
            decLength = 1;
        }
        if (maxLength < incLength) maxLength = incLength;
        if (maxLength < decLength) maxLength = decLength;
    }

    return maxLength;
}
