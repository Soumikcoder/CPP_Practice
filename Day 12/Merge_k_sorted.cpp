#include <bits/stdc++.h> 
#define pa pair<int,int> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    vector<int> ans;
    priority_queue<pa,vector<pa>,greater<pa>> pq;
    for (int i = 0; i < k; i++) {
      pq.push({kArrays[i][0],i});
    }
    vector<int> idx(k,0);
    while(!pq.empty()){
        pa val=pq.top();
        pq.pop();
        ans.push_back(val.first);
        idx[val.second]++;
        if(idx[val.second]<kArrays[val.second].size()){
            pq.push({kArrays[val.second][idx[val.second]],val.second});
        }
    }
    return ans;
}
