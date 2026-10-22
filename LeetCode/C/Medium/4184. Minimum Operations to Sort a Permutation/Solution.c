int min(int a, int b) {
    return a < b ? a : b;
}

int minOperations(int* nums, int numsSize) {

    int n = numsSize;

    int sortinc = 1;
    int sortdec = 1;

    for (int i = 0; i < n; i++) {

        if (nums[i] != (nums[(i - 1 + n) % n] + 1) % n)
            sortinc = 0;

        if (nums[i] != (nums[(i - 1 + n) % n] - 1 + n) % n)
            sortdec = 0;
    }

    if (sortinc) {

        int k = nums[0];

        int a = (n - k) % n;
        int b = k + 2;

        return min(a, b);
    }

    if (sortdec) {

        int k = nums[0];

        int a = n - k;
        int b = k + 2;

        return min(a, b);
    }

    return -1;
}