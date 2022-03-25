class Solution {
public:
    int maximumScore(int a, int b, int c) {
    vector<int> v={a,b,c};
    int ans=0;
    while(1)
    {   if(v[0]+v[1]==0 or v[1]+v[2]==0 or v[0]+v[2]==0)
            break;
        sort(v.begin(),v.end(),greater<int>());
        if(v[2]==0)
        {
            ans+=v[1];
            break;
        }
        ans++;
        v[2]--;
        v[0]--;
    }
        return ans;
    }
};