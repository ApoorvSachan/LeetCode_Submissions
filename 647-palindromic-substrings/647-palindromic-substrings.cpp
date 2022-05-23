class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size(), c=0,l,r;
        for(int i=0;i<n;i++)
        {
            l=i; r=i;
            while(l>=0 && r<n && s[l]==s[r]) 
            {
                c++;
                l--;
                r++;
            }
        }
         for(int i=0;i<n-1;i++)
        {
            l=i; r=i+1;
            while(l>=0 && r<n && s[l]==s[r]) 
            {
                c++;
                l--;
                r++;
            }
        }
        return c;
    }
};