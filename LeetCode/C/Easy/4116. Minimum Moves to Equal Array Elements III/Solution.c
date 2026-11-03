int minMoves(int* nums, int numsSize) {
    int max=nums[0];
    for(int i=0; i<numsSize; i++){
        if(max<nums[i]) max=nums[i];
    }
    int out=0;
    for(int i=0; i<numsSize; i++){
        out+=(max-nums[i]);
    }
    return out;
}