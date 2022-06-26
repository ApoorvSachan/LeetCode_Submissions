class Solution {
public:
    int fun(vector<int>& nums1, vector<int>& nums2){
        int sum=0, ans=0;
        for(int i=0;i<nums1.size();i++)
        {
            sum+=nums2[i]-nums1[i];
            ans=max(sum,ans);
            if(sum<0) sum=0;
        }
        for(auto i:nums1) ans+=i;
        return ans;
    }
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
       return max(fun(nums1,nums2),fun(nums2,nums1)); 
    }
};