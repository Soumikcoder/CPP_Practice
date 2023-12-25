class Solution {
public:
    int trap(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int max_left=0;
        int max_right=0;
        int water=0;
        while(i<j){
            if(height[i]<=height[j]){
                if(max_left<=height[i]) max_left=height[i++];
                else water+=(max_left-height[i++]);
            }
            else{
                if(max_right<=height[j]) max_right=height[j--];
                else water+=(max_right-height[j--]);
            }
        }
        return water;
    }
};