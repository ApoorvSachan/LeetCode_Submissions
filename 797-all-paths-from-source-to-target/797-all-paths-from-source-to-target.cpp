class Solution {
public:
    void dfs(int s, int &d, vector<vector<int>>& graph, vector<int> &p , vector<vector<int>> &ans)
    {   
        if(s==d) 
        {
            p.push_back(s);
            ans.push_back(p);
            p.pop_back();
            return;
        }
        p.push_back(s);
        for(auto i:graph[s])
        {
            dfs(i,d,graph,p,ans);
        }
        p.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
      vector<vector<int>> ans;
      vector<int> p;
      int d=graph.size()-1;
      dfs(0,d,graph,p,ans);
      return ans;
    }
};