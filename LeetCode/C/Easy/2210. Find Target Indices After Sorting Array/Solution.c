/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cum(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}
int* targetIndices(int* nums, int numsSize, int target, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), cum);
    int max=0;
    for(int i=0; i<numsSize; i++){
        if(nums[i]==target) max++;
    }
    int *out=(int*)calloc(max+1,sizeof(int));
    int k=0;
    for(int i=0; i<numsSize; i++){
        if(nums[i]==target) out[k++]=i;
    }
    *returnSize=k;
    return out;
}