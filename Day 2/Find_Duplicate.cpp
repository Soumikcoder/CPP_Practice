class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast=nums[nums[0]];
        int slow=nums[0];
        while(fast!=slow){
            fast=nums[nums[fast]];
            slow=nums[slow];
        }
        slow=0;
        while(nums[fast]!=nums[slow]){
            fast=nums[fast];
            slow=nums[slow];
        }
        return nums[fast];
    }
};