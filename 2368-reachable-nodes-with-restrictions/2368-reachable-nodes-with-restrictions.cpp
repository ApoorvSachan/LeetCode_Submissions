class Solution {
public:
    int dfs(vector<vector<int>> &graph, int s, vector<int> &vis, vector<int> &re){
        int ans=1;
        vis[s]=1;
        for(auto i:graph[s]){
            if(vis[i]==0 && re[i]==0)
                ans+=dfs(graph,i,vis,re);
        }
        return ans;
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
      vector<vector<int>> graph(n);
     for(auto i:edges){
         graph[i[0]].push_back(i[1]);
         graph[i[1]].push_back(i[0]);
     }
     vector<int> vis(n,0);
     vector<int> re(n,0);
     for(auto i:restricted) re[i]=1;
     return dfs(graph,0,vis,re);
    }
};