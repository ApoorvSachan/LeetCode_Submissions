class Solution {
public:
    int minSteps(string s, string t) {
    map<char,int> m1, m2;
    for(int i=0;i<s.size();i++){
        m1[s[i]]++;
        m2[t[i]]++;
    }
    int ans=0;
    for(auto i:m1){
       if(i.second>m2[i.first])
           ans+=(i.second-m2[i.first]);
    }
    return ans;
    }
};