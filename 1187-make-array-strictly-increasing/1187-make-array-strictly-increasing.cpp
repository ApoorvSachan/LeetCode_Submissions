class Solution {
public:
    int dp[2001][2001][2];
    int fun(vector<int> &a, vector<int> &b, int i, int j, int rep){
        if(i==a.size()) return 0;
        if(dp[i][j][rep]!=-1) return dp[i][j][rep];
        int an1=INT_MAX, an2=INT_MAX;
        int prev;
        if(rep) prev=b[j-1];
        else prev=i==0?-1:a[i-1];
        if(prev<a[i]){
            if(j<b.size()){
            int c=fun(a,b,i+1,j+1,1);
            if(c!=INT_MAX)
            an1=1+c;}
            int r=upper_bound(b.begin(),b.end(),a[i])-b.begin();
            an2=fun(a,b,i+1,r,0);
            return dp[i][j][rep]=min(an1,an2);
        }
        else{
               if(j<b.size()){
               int c=fun(a,b,i+1,j+1,1);
               if(c!=INT_MAX)
               an1=1+c;
               return dp[i][j][rep]=an1;}
        }
        return dp[i][j][rep]=INT_MAX;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
       set<int> s;
       for(auto i:arr2) s.insert(i);
       vector<int> b(s.begin(),s.end());
       memset(dp,-1,sizeof(dp));
       int ans=fun(arr1,b,0,0,0);
       return ans==INT_MAX?-1:ans;
    }
};