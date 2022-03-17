class Solution {
public:
    void fun(bitset<32> &b, int n, vector<int> &ans)
    {
        if(n==0) 
        {
            ans.push_back(b.to_ulong());
            return;
        }
        fun(b,n-1,ans);
        b.flip(n-1);
        fun(b,n-1,ans);
    }
    vector<int> grayCode(int n) {
        bitset<32> b;
        vector<int> ans;
        fun(b,n,ans);
        return ans;
    }
};