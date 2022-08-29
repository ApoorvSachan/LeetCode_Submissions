class Solution {
public:
    int dp[21][21];
    int fun(vector<int> &nums, int l, int r){
        if(l>r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        return dp[l][r]=max(nums[l]-fun(nums,l+1,r),nums[r]-fun(nums,l,r-1));
    }
    bool PredictTheWinner(vector<int>& nums) {
      memset(dp,-1,sizeof(dp));
      if(fun(nums,0,nums.size()-1)>=0)
          return true;
      return false;
    }
};