class Solution {
public:
    bool canConstruct(string s, int k) {
    if(s.size()<k) return false;
    if(s.size()==k) return true;
    unordered_map<char,int> m;
    int pair=0, distinct=0;
    for(auto i:s) m[i]++;
    for(auto i:m){
        pair+=i.second/2;
        distinct+=i.second%2;
    }
    if(distinct>k) return false;
    return true;
    }
};