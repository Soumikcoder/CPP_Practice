class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        map<long,int> hashmap;
        set<vector<int>> ans_set={};
        int N=nums.size();
        for(int j=0;j<(N-2);j++){
            for(int k=j+1;k<(N-1);k++){
            long long new_target=(long long)target-nums[k]-nums[j];
            hashmap={};
                for(int i=k+1;i<N;i++){
                    if(hashmap.find(nums[i])==hashmap.end()){
                        hashmap.insert(pair<long,int> ((new_target-nums[i]),i));
                    }
                    else{
                        vector<int> tmp={nums[j],nums[k],nums[hashmap[nums[i]]],nums[i]};
                        sort(tmp.begin(),tmp.end());
                        ans_set.insert(tmp);
                    }
                }
            }
        }
        vector<vector<int>> ans(ans_set.begin(),ans_set.end());
        return ans;
    }
};