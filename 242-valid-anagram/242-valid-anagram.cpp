class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return 0;
        map<char,int> m;
        for(int i=0;i<s.length();i++)
        {
            m[s[i]]++;
            m[t[i]]--;
        }
        for(auto i:m)
            if(i.second!=0) return 0;
        return 1;
    }
};