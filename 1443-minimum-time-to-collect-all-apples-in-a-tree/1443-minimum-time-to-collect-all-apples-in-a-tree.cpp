class Solution {
public:
    int ans=0;
    bool dfs(vector<vector<int>> &graph, int i, int parent, vector<bool>& hasApple){
        int p=hasApple[i];
        for(auto n:graph[i])
        {
          if(n==parent) continue;
          ans++;
          if(dfs(graph,n,i,hasApple)){
            ans++;
            p=1;
          }
          else ans--;
        }
        return p;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> graph(n);
        for(auto i:edges){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        return dfs(graph,0,-1,hasApple)?ans:0;
    }
};