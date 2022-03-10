class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mi=INT_MIN,ma=prices[0];
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]<ma) ma=prices[i];
            else
            mi=max(mi,prices[i]-ma);
        }
        if(mi<0) return 0;
        return mi;
    }
};