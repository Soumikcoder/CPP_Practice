void sortColors(int* nums, int numsSize){
    int count[3];
    memset(count,0,3*sizeof(int));
    for(int i=0;i<numsSize;i++) count[nums[i]]++;
    int j=0;
    for(int i=0;i<3;i++){
        while(count[i]>0){
            nums[j++]=i;
            count[i]--;
        }
    }
}