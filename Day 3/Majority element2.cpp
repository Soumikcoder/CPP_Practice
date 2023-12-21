class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int number=0;
        int count=0;
        int number2=-1;
        int count2=0;
        int N=nums.size();
        for(int i=0;i<N;i++){
            if(count==0 && nums[i]!=number2){
                number=nums[i];
                count++;
            }
            else if(count2==0 && nums[i]!=number){
                number2=nums[i];
                count2++;
            }
            else if(nums[i]==number){
                count++;
            }
            else if(nums[i]==number2){
                count2++;
            }
            else{
                count--;
                count2--;
            }
        }
        count=0;count2=0;
        for(int i=0;i<N;i++) {
            if(nums[i]==number) count++;
            if(nums[i]==number2) count2++;
        }
        if(count>(N/3) && count2>(N/3))
            return {number,number2};
        else if((count2>(N/3)))
            return {number2};
        else if(count>(N/3))
        return {number};
        else
            return {};
    }
};