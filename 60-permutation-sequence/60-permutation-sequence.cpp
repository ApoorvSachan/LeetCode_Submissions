class Solution {
public:
    int fact(int n){
        vector<int> dp(n+1);
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]*i;
        }
        return dp[n];
    }
    string getPermutation(int n, int k) {
        set<int> s;
        string ans;
        for(int i=1;i<=n;i++)
            s.insert(i);
        for(int i=1;i<=n;i++){
            if(k==1){for(auto j:s)
                        ans+=('0'+j);
            break;}
            if(k==0){
                string temp;
                for(auto j:s) temp+=('0'+j);
                reverse(temp.begin(),temp.end());
                ans+=temp;
                break;}
            int d=fact(n-i);
            int t=ceil((float)k/d);
            t--;
            auto it=s.begin();
            while(t--) it++;
            ans+=('0'+*it);
            s.erase(it);
            k=k-((k/d)*d);
        }
        return ans;
    }
};