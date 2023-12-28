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
            for(int i=start;i<candidates.size();i++){
            if(i!=start && candidates[i-1]==candidates[i]) continue;
            if(candidates[i]<=target){
                temp.push_back(candidates[i]);
                sum(candidates,target-candidates[i],i+1,temp,ans);
                temp.pop_back();
            }
            else{
                break;
            }
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans={};
        vector<int> temp={};
        sort(candidates.begin(),candidates.end());
        sum(candidates,target,0,temp,ans);
        return ans;
    }
};