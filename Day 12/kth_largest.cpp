class Solution {
public:
    static int partition(vector<int>& a, int low , int high){
        int pivot=a[low];
        int p=low;
        int q=high+1;
        while(p<q){
            while(p<high && a[++p]<pivot);
            while(q>0 && a[--q]>pivot);
            if(p<q)
            swap(a[p],a[q]);
        }
        swap(a[q],a[low]);
        return q;
    }
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size()==1) return nums[0];
        int high=nums.size()-1;
        int n=nums.size();
        int low=0;
        while(1){
            int part=partition(nums,low,high);
            if((n-k)==part) return nums[part];
            else if((n-k)>part) low=part+1;
            else high=part-1;
        }
        return nums[low];
    }
};