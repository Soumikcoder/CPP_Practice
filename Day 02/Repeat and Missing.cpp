vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int xor_ans=0;
    for(int i=0;i<A.size();i++){
        xor_ans^=(i+1);
        xor_ans^=A[i];
        
    }
    int x=0;
    int y=0;
    
    xor_ans=(xor_ans&~(xor_ans-1));
    for(int i=0;i<A.size();i++){
        if((xor_ans&(i+1))!=0){
            x^=(i+1);
        }else{
            y^=(i+1);
        }
        
        
        if((xor_ans&A[i])!=0){
            x^=A[i];
        }
        else{
            y^=A[i];
        }
    }
    vector<int> ans;
    int count=0;
    for(int i=0;i<A.size();i++){
        if(A[i]==x) count++;
    }
    if(count==2)
    return {x,y};
    else
    return {y,x};
}
