class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count=0;
        int N=s.size();
        int max_count=0;
        map<char,int> hashmap;
        int r=0;
        for(int i=0;i<N;i++){
            if(i==0 || hashmap.find(s[i])==hashmap.end()){
                count++;
                hashmap.insert(pair<char,int> (s[i],i));   
            }
            else{
                r=max(hashmap[s[i]],r);
                count=(i-r);
                hashmap[s[i]]=i;
            }
            max_count=max(count,max_count);
        }
        return max_count;
    }
};