class Solution {
public:
    int mod=1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++) v.push_back({efficiency[i],speed[i]});
    sort(v.begin(),v.end());
    set<pair<int,int>> s;
    long long sum=0, ans=0;
    for(int i=n-1;i>=0;i--){
        if(s.size()>=k){
            sum-=(*s.begin()).first;
            s.erase(*s.begin());
        }
        sum+=v[i].second;
        s.insert({v[i].second,v[i].first});
        ans=max(ans,sum*v[i].first);
    }
    return ans%mod;
    }
};