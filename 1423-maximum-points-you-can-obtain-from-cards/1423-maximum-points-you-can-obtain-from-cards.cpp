class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int l=cardPoints.size()-k;
        int sum=0, tsum=0;
        for(int i=0;i<l;i++) sum+=cardPoints[i];
        int ans=sum;
        int i=0, j=l;
        while(j<cardPoints.size())
        {
            sum-=cardPoints[i];
            sum+=cardPoints[j];
            ans=min(ans,sum);
            j++;i++;
        }
        for(auto i:cardPoints) tsum+=i;
        return tsum-ans;
    }
};