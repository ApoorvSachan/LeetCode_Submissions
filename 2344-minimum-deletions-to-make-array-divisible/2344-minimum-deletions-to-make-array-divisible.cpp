class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
     int g=numsDivide[0];
        for(auto i:numsDivide)
            g=gcd(g,i);
        sort(nums.begin(),nums.end());
        int ans=0;
        for(auto i:nums)
        {
            if(g%i==0) break;
            ans++;
        }
        return ans==nums.size()?-1:ans;
    }
};