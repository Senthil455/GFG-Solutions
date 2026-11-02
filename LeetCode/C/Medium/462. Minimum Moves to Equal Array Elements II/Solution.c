int cmpFunc(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int minMoves2(int* nums, int numsSize) {
    int result=0;

    qsort(nums, numsSize, sizeof(int), cmpFunc);
    for(int i=0, median=nums[numsSize/2]; i<numsSize; i++)
    { result+=abs(median-nums[i]); }

    return result;
}