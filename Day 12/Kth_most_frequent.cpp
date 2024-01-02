#define pa pair<int,int>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<pa,vector<pa>> maxheap;
        for(auto i: mp){
            maxheap.push({i.second,i.first});
        }
        while(k--){
            ans.push_back((maxheap.top()).second);
            maxheap.pop();
        }
        return ans;
    }
};