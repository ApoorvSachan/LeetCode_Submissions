class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      vector<vector<string>> ans;
      map<string,vector<string>> m;
      for(int i=0;i<strs.size();i++)
      {   string t=strs[i];
          sort(t.begin(),t.end());
          m[t].push_back(strs[i]);         
      }
      
      for(auto i=m.begin();i!=m.end();i++)
      {   vector<string> v;
          for(int j=0;j<m[i->first].size();j++)
          v.push_back((i->second)[j]);
        ans.push_back(v);
      }
      return ans;
    }
};