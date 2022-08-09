class Solution {
public:
    int mod=1e9+7;
    map<long long,long long> dp;
    int trees(int root, unordered_map<int,int> &m){
        if(dp.find(root)!=dp.end()) return dp[root];
        long long ans=1;
        for(int i=1;i*i<=root;i++){
            if(root%i==0 && m.find(i)!=m.end() && m.find(root/i)!=m.end())
            {
                long long temp=((long long)trees(i,m)*trees(root/i,m))%mod;
                if(i!=root/i)
                    temp=(temp*2)%mod;
                ans=(ans+temp)%mod;
            }
        }
        return dp[root]=ans;
    }
    int numFactoredBinaryTrees(vector<int>& arr) {
       unordered_map<int,int> m;
        for(auto i:arr)
            m[i]=1;
        long long ans=0;
        for(auto i:arr)
            ans=(ans+trees(i,m))%mod;
        return ans;
    }
};