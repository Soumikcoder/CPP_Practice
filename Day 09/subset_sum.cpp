class Solution
{
public:
    static void summer(vector<int> &arr,int start,int sum,int N,vector<int> &ans){
        if(start==arr.size() || N==0) {
            ans.push_back(sum);
        }
        else{
            summer(arr,start+1,sum,N,ans);
            summer(arr,start+1,sum+arr[start],N-1,ans);
        }
        return;
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans={};
        summer(arr,0,0,N,ans);
        return ans;
    }
};