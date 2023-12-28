class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> hashset={};
        int N=nums.size();
        for(int i=0;i<N;i++){
            hashset.insert(nums[i]);
        }
        int max_length=0;
        int count=0;
        int prev;
        for(auto i:hashset){
            if(count==0){
                prev=i;
                count++;
            }
            else if(prev!=(i-1)){
                count=1;
                prev=i;
            }
            else{
                count++;
                prev++;
            }
            max_length=max(max_length,count);
        }
        return max_length;
    }
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int N=nums.size();
        int max_length=0;
        int count=0;
        int prev;
        for(int i=0;i<N;i++){
            if(count==0){
                prev=nums[i];
                count++;
            }
            else if(prev!=(nums[i]-1) && prev!=nums[i]){
                count=1;
                prev=nums[i];
            }
            else if(prev==(nums[i]-1)){
                count++;
                prev++;
            }
            max_length=max(max_length,count);
        }

        return max_length;
    }
};