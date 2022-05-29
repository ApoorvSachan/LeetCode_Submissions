class Solution {
public:
    void dfs(int s, vector<bool> &vis, vector<vector<int>> &graph)
    {
        vis[s]=1;
        for(auto i:graph[s])
        {
            if(!vis[i])
                dfs(i,vis,graph);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
       int n=isConnected.size();
       vector<vector<int>> graph(n);
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<n;j++)
           {
               if(i!=j && isConnected[i][j]==1)
               {   graph[i].push_back(j);
                   graph[j].push_back(i);
               }
           }
       }
        vector<bool> vis(n,0);
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,graph);
                count++;
            }
        }
        return count;
    }
};