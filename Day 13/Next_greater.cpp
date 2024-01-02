class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       unordered_map<int,int> m;
        stack<int> st;

        int n = nums2.size();

        for(int i = n-1; i>=0; i--)
          {
              while(!st.empty() && nums2[i]>st.top())
                {
                    st.pop();
                }

                if(st.empty())
                   m[nums2[i]] = -1;
                else
                   m[nums2[i]] = st.top();
               st.push(nums2[i]);       
          }


          vector<int> res;
          for(auto it : nums1)
            {
                res.push_back(m[it]);
            }

            return res; 
    }
};