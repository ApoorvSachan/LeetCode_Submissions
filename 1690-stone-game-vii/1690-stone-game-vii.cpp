class Solution {
public:
    int dp[1001][1001];
    int fun(vector<int> &s, int l, int r, vector<int> &ps){
        if(l>r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        int left=(ps[r]-ps[l])-fun(s,l+1,r,ps);
        int right=((r==0?0:ps[r-1])-(l==0?0:ps[l-1]))-fun(s,l,r-1,ps);
        return dp[l][r]=max(left,right);
    } 
    int stoneGameVII(vector<int>& stones) {
        memset(dp,-1,sizeof(dp));
        vector<int> pre_sum(stones.size(),0);
        pre_sum[0]=stones[0];
        for(int i=1;i<stones.size();i++)
            pre_sum[i]=pre_sum[i-1]+stones[i];
        return fun(stones,0,stones.size()-1,pre_sum);
    }
};