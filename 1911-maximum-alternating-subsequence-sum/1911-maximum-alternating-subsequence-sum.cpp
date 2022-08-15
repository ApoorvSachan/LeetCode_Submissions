class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<vector<long long>> dp(nums.size()+1, vector<long long> (2,0));
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=0; j<2; j++){
                long long ans;
                if(j==0) ans=nums[i]+dp[i+1][1];
                else ans=dp[i+1][0]-nums[i];
                dp[i][j]=max(ans,dp[i+1][j]);
            }
        }
        return dp[0][0];
    }
};