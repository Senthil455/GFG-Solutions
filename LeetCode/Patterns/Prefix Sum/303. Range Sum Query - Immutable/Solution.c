typedef struct { int *n; } NumArray;
NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray *n = malloc(sizeof *n);
    if (n) {
        n->n = malloc(sizeof(int [numsSize]));
        for (int i = 0 ; i < numsSize ; i++)
            n->n[i] = i > 0 ? nums[i] + n->n[i - 1] : nums[i];
    }
    return n;
}
int numArraySumRange(NumArray* obj, int left, int right) {
    return obj->n[right] - (left > 0 ? obj->n[left - 1] : 0);
}
void numArrayFree(NumArray* obj) {
    free(obj);
}