class Solution {
public:
    int dp[501];
    int fun(vector<int> &a, int i, int &k){
        if(i>=a.size())
            return 0;
        if(dp[i]!=-1) return dp[i];
        int maxi=a[i], maxsum=0;
        for(int p=0;p<k && p+i<a.size();p++){
            maxi=max(maxi,a[i+p]);
            maxsum=max(maxsum,maxi*(p+1)+fun(a,i+p+1,k));
        }
        return dp[i]=maxsum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof(dp));
        return fun(arr,0,k);  
    }
};