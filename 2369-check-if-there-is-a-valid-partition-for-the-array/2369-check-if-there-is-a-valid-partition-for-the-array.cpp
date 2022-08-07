class Solution {
public:
    int dp[100002];
    bool fun(vector<int>& nums, int i){
      if(i==nums.size())return 1;
      if(i+1>=nums.size()) return 0;
      if(dp[i]!=-1) return dp[i];
      bool ans1=0, ans2=0;
      if(nums[i]==nums[i+1]){
          ans1=fun(nums,i+2);
      }
      if(i+2>=nums.size()) return dp[i]=ans1;
      if((nums[i]==nums[i+1] && nums[i+1]==nums[i+2]) || (nums[i]+1==nums[i+1] && nums[i+1]+1==nums[i+2]))
      {
          ans2=fun(nums,i+3);
      }
        return dp[i]=ans1|ans2;
    }
    bool validPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
       return fun(nums,0); 
    }
};