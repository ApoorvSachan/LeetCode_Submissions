class Solution {
public:
    bool isPossible(vector<int>& nums) {
     map<int,priority_queue<int,vector<int>,greater<int>>> m;
     for(auto i:nums){
          if(m.find(i-1)!=m.end() && !m[i-1].empty()){
              int l=m[i-1].top()+1;
              m[i-1].pop();
              m[i].push(l);
          }
          else
              m[i].push(1);
      }
     for(auto i:m){
         while(!i.second.empty()){
             if(i.second.top()<3) return false;
             i.second.pop();
         }
     }
     return true;
    }
};