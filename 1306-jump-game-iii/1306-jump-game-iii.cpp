class Solution {
public:
    bool fun(vector<int>& a, int i, vector<bool> &vis)
    {
        if(i<0 || i>=a.size() || vis[i]==1) return 0;
        if(a[i]==0) return 1;
        vis[i]=1;
        return (fun(a,i+a[i],vis) || fun(a,i-a[i],vis));
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool> vis(arr.size(),0);
        return fun(arr,start,vis);
    }
};