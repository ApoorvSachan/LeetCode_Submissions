class Solution {
public:
int dp[101][101][21];
int fun(vector<int>& houses, vector<vector<int>>& cost, int i, int target, int last_clr) {
    if (i >= houses.size() || target < 0)
        return target == 0 ? target : 1000001;
    if (houses[i] != 0)
        return fun(houses, cost, i + 1, target - (last_clr != houses[i]), houses[i]);      
    if (dp[i][target][last_clr]!=-1)
        return dp[i][target][last_clr];
    int res = 1e9+7;
    for (int clr = 1; clr <= cost[i].size(); ++clr) {
        res = min(res, cost[i][clr - 1]+fun(houses, cost, i + 1, target - (last_clr != clr), clr));
    }            
    return dp[i][target][last_clr] = res;
}
int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
    memset(dp,-1,sizeof(dp));
    int res = fun(houses, cost, 0, target, 0);
    return res > 1000000 ? -1 : res;
}
};