#include <bits/Stdc++.h>
class Solution {
public:
    set<int> rows;
    set<int> cols;
    void setZeroes(vector<vector<int>>& matrix) {
        for (int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                     rows.insert(i);
                     cols.insert(j);
                }   
            }
        }
        for (int i=0;i<matrix.size();i++){
            int zero_cols=0;
            if(rows.find(i)!=rows.end()){
                zero_cols=1;
            }
            for(int j=0;j<matrix[i].size();j++){
                if(zero_cols){
                    matrix[i][j]=0;
                }
                else if(cols.find(j)!=cols.end()){
                    matrix[i][j]=0;
                }
            }
        }
    }
};
int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}