class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
    unordered_map<int,int> m;
        for(auto i:deck)
            m[i]++;
        int ans=m.begin()->second;
        for(auto i:m)
            ans=__gcd(ans,i.second);
        return ans>1?1:0;
    }
};