class Solution {
public:
    int maxlen=0, maxpl, maxpr;
    string longestPalindrome(string s) {
        for(int i=0; i<s.length(); i++)
        {
            int l=i, r=i, len=0;
            while(l>=0 && r<s.size() && s[l]==s[r])
            {
                if(l==r) len++;
                else len+=2;
                l--; r++;
            }
            if(len>maxlen)
            {
                maxlen=len;
                maxpl=l+1; maxpr=r-1;
            }
            l=i, r=i+1, len=0;
            while(l>=0 && r<s.size() && s[l]==s[r])
            {
                len+=2;
                l--; r++;
            }
            if(len>maxlen)
            {
                maxlen=len;
                maxpl=l+1; maxpr=r-1;
            }
        }
        string maxp=s.substr(maxpl,maxpr-maxpl+1);
        return maxp;
    }
};