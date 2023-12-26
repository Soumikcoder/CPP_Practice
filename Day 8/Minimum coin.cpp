int binarysearch(int *arr,int size,int value){
    int low=0;
    int high=size-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]<=value && value<arr[mid+1]){
            return mid;
        }
        else if (arr[mid]>value){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}
vector<int> MinimumCoins(int n)
{
    int currency[]={1,2,5,10,20,50,100,500,1000};
    int N=sizeof(currency)/sizeof(currency[0]);
    int i;
    if (n <= currency[N - 1]) {
       i= binarysearch(currency, N, n);
    } else {
       i = N - 1;
    }
    vector<int> coin;
    while(i>=0){
        if(currency[i]<=n){
            coin.push_back(currency[i]);
            n-=currency[i];
        } else {
            i--;
        }
    }
    return coin;
    // Write your code here
}