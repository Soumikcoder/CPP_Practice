#include <vector>
#include <string>
using namespace std;
class Solution{
    public:
    static bool issafe(vector<vector<int>> &m,int i,int j){
        if(i>=m.size() || j>=m.size()) return false;
        else if(i<0 || j<0 )return false;
        if(m[i][j]==1) return true;
        else return false;
    }
    static bool find( vector<string>& path,string& s,vector<vector<int>> &m,int i,int j){
        if(i>=(m.size()-1) && j>=(m.size()-1)){
            path.push_back(s);
            return false;
        }
        else if(i==m.size() || j==m.size()) return false;
        else if(i==-1 || j==-1 )return false;
        else{
            m[i][j]=0;
            if(issafe(m,i+1,j)){
                s.push_back('D');
                if(find(path,s,m,i+1,j)){
                    return true;
                }
                s.pop_back();
            }
            if(issafe(m,i,j+1)){
                s.push_back('R');
                if(find(path,s,m,i,j+1)){
                    return true;
                }
                s.pop_back();
            }
            if(issafe(m,i,j-1)){
                s.push_back('L');
                if(find(path,s,m,i,j-1)){
                    return true;
                }
                s.pop_back();
            }
            if(issafe(m,i-1,j)){
                s.push_back('U');
                if(find(path,s,m,i-1,j)){
                    return true;
                }
                s.pop_back();
            }
             m[i][j]=1;
            return false;
        }
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> path;
        string s;
        if(m[0][0]==0) return path;
        find(path,s,m,0,0);
        return path;
           
    }