long long pow(int m,int n,int key){
  long long ans=1;
  for(int i=1;i<=n;i++){
    ans=ans*m;
    if(ans>key) return 1;
  }
  if(ans==key) return 0;
  else return -1;
}
int NthRoot(int n, int m) {
  // Write your code here.
  int low=0;
  int high=m/n;
  while(low<=high){
    int mid =(low+high)/2;
    int val=pow(mid,n,m);
    if(val==0) return mid;
    else if(val>0) high=mid-1;
    else low=mid+1;
  }
  return -1;
}