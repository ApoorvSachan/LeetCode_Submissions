class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
      vector<int> f(10001,-1), ans;
        stack<int> s;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!s.empty() && s.top()<nums2[i])
                s.pop();
            if(!s.empty()) f[nums2[i]]=s.top();
            s.push(nums2[i]);
        }
        for(auto i:nums1){
           ans.push_back(f[i]); 
        }
        return ans;
    }
};