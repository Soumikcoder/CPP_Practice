class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> hashmap;
        int N=nums.size();
        for(int i=0;i<N;i++){
            if(hashmap.find(nums[i])==hashmap.end()){
                hashmap.insert(pair<int,int> ((target-nums[i]),i));
            }
            else{
                return {hashmap[nums[i]],i};
            }
        }
        return {};
    }
};