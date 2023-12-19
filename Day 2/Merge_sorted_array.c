void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i=nums1Size-1;
    if(n==0) return;
    else if(m==0) {
        while(i>=0)
        nums1[i--]=nums2[--n];
    }
    else{
        m--;n--;
    while(i>=0){
        if(n<0) return;
        else if(m<0) nums1[i--]=nums2[n--];
        else nums1[i--]=(nums1[m]>nums2[n]?nums1[m--]:nums2[n--]);
    }
    }
}