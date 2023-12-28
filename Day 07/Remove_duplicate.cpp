class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=1;
        int N=nums.size();
        while(j!=N){
            if(nums[i]!=nums[j])
                nums[++i]=nums[j];
            j++;
        }
        return i+1;
    }
};