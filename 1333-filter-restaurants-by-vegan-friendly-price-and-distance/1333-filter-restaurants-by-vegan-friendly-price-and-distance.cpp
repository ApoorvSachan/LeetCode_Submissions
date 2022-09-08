class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
    vector<pair<int,int>> v;
    for(auto i:restaurants){
       if(i[3]<=maxPrice && i[4]<=maxDistance){
           if(veganFriendly==0 || i[2]==1)
               v.push_back({i[1],i[0]});
       } 
    }  
    sort(v.begin(),v.end(),greater<pair<int,int>>());
    vector<int> ans;
    for(auto i:v) ans.push_back(i.second);
    return ans;
    }
};