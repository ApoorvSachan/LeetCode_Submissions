class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
     if(changed.size()%2!=0) return {};
     map<int,int> m;
     for(auto i:changed) m[i]++;
     int c=0;
     vector<int> ans;
     sort(changed.begin(),changed.end());
     for(auto i:changed){
         if(m.find(i)!=m.end() && m.find(2*i)!=m.end()){
            if(i==0 && m[i]==1) continue; 
            c++;
            m[2*i]--;
            m[i]--;
            if(m[i]==0) m.erase(i);
            if(m[2*i]==0) m.erase(2*i);
            ans.push_back(i);
         }
     }
     if(c<changed.size()/2) return{};
     return ans;
    }
};