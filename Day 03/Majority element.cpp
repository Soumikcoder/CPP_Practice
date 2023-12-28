class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int number=0;
        int count=0;
        int N=nums.size();
        for(int i=0;i<N;i++){
            if(count==0){
                number=nums[i];
                count++;
            }
            else if(nums[i]==number){
                count++;
            }
            else{
                count--;
            }
        }
        count=0;
        for(int i=0;i<N;i++) if(number==nums[i]) count++;
        if(count>(N/2)) return number;
        return -1;
    }
};