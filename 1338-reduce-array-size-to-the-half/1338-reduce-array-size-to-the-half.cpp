class Solution {
public:
    int minSetSize(vector<int>& arr) {
    int l=arr.size()/2;
    map<int,int> m;
    for(auto i:arr) m[i]++;
    vector<pair<int,int>> v;
    for(auto i:m) v.push_back({i.second,i.first});
    sort(v.rbegin(),v.rend());
    int ans=0, i=0;
    while(ans<l && i<v.size()){
        ans+=v[i].first;
        i++;
        }
    return i;
    }
};