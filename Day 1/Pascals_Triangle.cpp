class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        for(int i=0;i<numRows;i++){
            temp={};
            for(int j=0;j<(i+1);j++){
                if(j==0 ||j==i)
                temp.push_back(1);
                else
                temp.push_back(ans[i-1][j-1]+ans[i-1][j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};