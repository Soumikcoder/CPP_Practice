class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int N1=nums1.size();
        int N2=nums2.size();
        int size=(N1+N2);
        int n=(N1+N2)/2;
        int i=0;
        int j=0;
        int temp=0;
        int prev_temp=0;
        while(n>=0){
            prev_temp=temp;
            if(i==N1){
                temp=nums2[j++];
            }
            else if(j==N2){
                temp=nums1[i++];
            }
            else {
                if(nums1[i]<nums2[j]){
                    temp=nums1[i++];
                }
                else{
                   temp=nums2[j++]; 
                }
            }
            n--;
        }
        if(size&1) return temp;
        else{
            return 1.0*(prev_temp+temp)/2;
        }
    }
};