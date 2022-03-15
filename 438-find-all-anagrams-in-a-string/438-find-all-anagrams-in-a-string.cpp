class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pm(26,0), sm(26,0), ans;
        if(s.size()<p.size()) return {};
        for(int i=0;i<p.size();i++)
        {
            sm[s[i]-'a']++;
            pm[p[i]-'a']++;
        }
        if(sm==pm) ans.push_back(0);
     for(int i=1; i+p.size()-1<s.size();i++)
     {
         sm[s[i-1]-'a']--;
         sm[s[i+p.size()-1]-'a']++;
         if(sm==pm)
             ans.push_back(i);
     }
    return ans;
    }
};