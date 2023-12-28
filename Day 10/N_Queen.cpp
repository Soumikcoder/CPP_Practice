class Solution {
public:
    bool issafe(int i,int j,vector<string>&temp){
        for(int m=0;m<i;m++){
            if(temp[m][j]=='Q') return false;
        }     
        int row=i;
        int col=j;
        while(row>=0 && col>=0){
            if(temp[row--][col--]=='Q') return false;
        }
        row=i;
        col=j;
        while(row>=0 && col<temp.size()){
            if(temp[row--][col++]=='Q') return false;
        }
        return true;
    }
    bool solve(int i, vector<string>&temp , vector<vector<string>> &ans){
        if(i>=temp.size()){
            ans.push_back(temp);
            return false;
        }
        for(int m=0;m<temp.size();m++){
            if(issafe(i,m,temp)){
                temp[i][m]='Q';
                if(solve(i+1,temp ,ans)){
                    return true;
                }
                temp[i][m]='.';
            }
        }
        return false;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string>temp;
        string s;
        for(int j=0;j<n;j++){
            s.push_back('.');
        }
        for(int i=0;i<n;i++){  
            temp.push_back(s);
        }
        solve(0,temp,ans);
        return ans;
    }
};