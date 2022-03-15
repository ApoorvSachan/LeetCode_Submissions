class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1m(26,0), s2m(26,0);
        if(s1.size()>s2.size()) return 0;
        for(int i=0;i<s1.size();i++)
        {
            s1m[s1[i]-'a']++;
            s2m[s2[i]-'a']++;
        }
        if(s1m==s2m) return 1;
        for(int i=1; i+s1.size()-1<s2.size();i++)
        {
            s2m[s2[i-1]-'a']--;
            s2m[s2[i+s1.size()-1]-'a']++;
            if(s2m==s1m) return 1;
        }
        return 0;
    }
};