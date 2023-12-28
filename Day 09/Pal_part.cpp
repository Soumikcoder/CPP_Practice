class Solution {
public:
    static bool checkpal(string s,int i,int j){
        while(i<=j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    static void gen(string &s,int start,vector<string> &temp,vector<vector<string>> &ans){
        if(start==s.size()){
            ans.push_back(temp);
        }
        else{
            for(int i=start;i<s.size();i++){
                if(checkpal(s,start,i)){
                    temp.push_back(s.substr(start,(i+1-start)));
                    gen(s,i+1,temp,ans);
                    temp.pop_back();
                }
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> ans;
        gen(s,0,temp,ans);
        return ans;
    }
};