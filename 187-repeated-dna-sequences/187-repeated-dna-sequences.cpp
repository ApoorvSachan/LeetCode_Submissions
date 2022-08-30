class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
    vector<string> ans;
    if(s.size()<=10) return ans;
    unordered_map<string,int> m;
    string t=s.substr(0,10);
    m[t]++;
    for(int i=1;i<=s.size()-10;i++){
        m[s.substr(i,10)]++;
    }
    for(auto i:m){
        if(i.second>1)
            ans.push_back(i.first);
    }
    return ans;
    }
};