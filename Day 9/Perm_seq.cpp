class Solution {
public:
    string getPermutation(int n, int k) {
        string number;
        string ans;
        int fact=1;
        for(int i=1;i<n;i++){
            fact=fact*i;
            number.push_back('0'+i);
        }
        number.push_back('0'+n);
        k=k-1;
        for(int i=n-1;i>=0;i--){
            ans.push_back(number[k/fact]);
            number.erase(k/fact,1);
            k=k%fact;
            if(i!=0)
            fact=fact/i;
        }
        return ans;
    }
};