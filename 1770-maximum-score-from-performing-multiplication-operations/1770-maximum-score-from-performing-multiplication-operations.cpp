class Solution {
public:
    int dp[1001][1001];
/*    int fun(vector<int> &nums, vector<int> &multi, int i, int j){
        if(j==multi.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int sum=0, e=nums.size()-(j-i)-1;
        int l=multi[j]*nums[i]+fun(nums,multi,i+1,j+1);
        int r=multi[j]*nums[e]+fun(nums,multi,i,j+1);
        return dp[i][j]=max(l,r);
    }*/
    int maximumScore(vector<int>& nums, vector<int>& multi) {
       memset(dp,0,sizeof(dp));
       for(int i=multi.size()-1;i>=0;i--){
           for(int j=multi.size()-1;j>=i;j--){
               int e=nums.size()-(j-i)-1;
               int l=multi[j]*nums[i]+dp[i+1][j+1];
               int r=multi[j]*nums[e]+dp[i][j+1];
               dp[i][j]=max(l,r);
           }
       }
       return dp[0][0]; 
    }
};