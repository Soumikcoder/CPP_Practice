class Solution {
public:
    static void sum(vector<int>& candidates,int target,int start,vector<int>& temp, vector<vector<int>>& ans){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        else if(start==candidates.size()){
            return;
        }
        else{
            sum(candidates,target,start+1,temp,ans);
            if(candidates[start]<=target){
                temp.push_back(candidates[start]);
                sum(candidates,target-candidates[start],start,temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans={};
        vector<int> temp={};
        sum(candidates,target,0,temp,ans);
        return ans;
    }
};