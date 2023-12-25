class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int N=nums.size();
        vector<vector<int>> temp={};
        for(int i=0;i<(N-2);i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k=N-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum>0){
                    k--;
                }
                else if(sum<0){
                    j++;
                }
                else{
                    temp.push_back({nums[i],nums[j],nums[k]});
                    while(j<k && nums[++j]==nums[j-1]);
                    while(j<k && nums[--k]==nums[k+1]);
                }
            }
        }
        return temp;
    }
};