class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
      int len=0, sum=0, ans=1e9+7, l=0;
      for(auto i:nums){
         sum+=i;
         len++;
         while(sum>=target){
         ans=min(ans,len);
         sum-=nums[l];
         l++;
         len--;
         }
      }
        return ans==1e9+7?0:ans;
    }
};