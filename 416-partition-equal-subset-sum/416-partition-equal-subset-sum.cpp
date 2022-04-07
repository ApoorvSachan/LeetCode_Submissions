class Solution {
public:
    bool helper(vector<int> &n, int i, int target, vector<vector<int>> &dp)
    {
        if(target==0) return 1;
        if(i==0) return n[0]==target;
        if(dp[i][target]!=-1) return dp[i][target];
        bool npick=helper(n,i-1,target,dp);
        bool pick=0;
        if(n[i]<=target)
            pick=helper(n,i-1,target-n[i],dp);
        return dp[i][target]=pick | npick;
            
    }
    bool canPartition(vector<int>& nums) {
        int tsum=0;
        for(auto i:nums)
            tsum+=i;
        if(tsum%2!=0) return 0;
        
        vector<vector<int>> dp(nums.size(), vector<int> (tsum+1,-1));
        return helper(nums,nums.size()-1,tsum/2, dp);
    }
};