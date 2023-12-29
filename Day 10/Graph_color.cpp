bool issafe(vector<vector<int>> &mat,int color,int i,vector<int> &color_mat){
    for(int j=0;j<mat.size();j++){
        if(j!=i && mat[i][j]==1 && color_mat[j]==color) return false;
    }
    return true;
}
bool graphcol(vector<vector<int>> &mat,vector<int> &color_mat,int i,int m){
    if(i==mat.size()) return true;
    else{
        for(int color=0;color<m;color++){
            if(issafe(mat,color,i,color_mat)){
                color_mat[i]=color;
                if(graphcol(mat,color_mat, i+1, m)){
                    return true;
                }
                color_mat[i]=-1;
            }
        }
        return false;
    }
}
string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    vector<int> color(mat.size(),-1);
    if(graphcol(mat, color,0, m)){
        return "YES";
    }
    else{
        return "NO";
    }
}