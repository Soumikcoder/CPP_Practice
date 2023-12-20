class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans={};
        vector<int> temp={};
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++){
            if(temp.size()==0){
                temp.push_back(intervals[i][0]);
                temp.push_back(intervals[i][1]);
            }
            else if(intervals[i][0]<=temp[1]){
                if(temp[1]<intervals[i][1])
                    temp[1]=intervals[i][1];
            }
            
            else{
                    ans.push_back(temp);
                    temp={};
                    temp.push_back(intervals[i][0]);
                    temp.push_back(intervals[i][1]);
                }
            }
            
        
        ans.push_back(temp);
        return ans;
    }
};