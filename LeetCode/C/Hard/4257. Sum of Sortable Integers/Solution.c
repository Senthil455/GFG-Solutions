int sortableIntegers(int* nums, int numsSize) {
    int sum=0;
    for(int i=1; i<=numsSize; i++) {
        if(numsSize%i==0) {
            int size=i;
            int prev=INT_MIN;

            for(int j=0; j<numsSize; j+=size) {
                int count=0;
                int max=INT_MIN;
                int min=INT_MAX;

                for(int k=j; k<j+size; k++) {
                    if(nums[k]>=max) {
                        max=nums[k];
                    }
                    if(nums[k]<=min) {
                        min=nums[k];
                    }
                    if(k==j) {
                        continue;
                    }
                    else {
                        if(nums[k]<nums[k-1]) {
                            count++;
                        }
                    }
                }

                if(count==1 && nums[j+size-1]>nums[j]) {
                    goto end;
                }

                if(count>1) {
                    goto end;
                }
                else {
                    if(min>=prev) {
                        prev=max;
                    }
                    else {
                        goto end;
                    }
                }
            }
            sum=sum+size;
        }
        end:;
    }
    return sum;
}