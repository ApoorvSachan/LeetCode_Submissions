class Solution {
public:
    vector<int> color;
    void dfs(vector<vector<int>> &graph, int n){
        if(color[n]) return;
        unordered_set<int> s;
        for(auto i:graph[n])
            s.insert(color[i]);
        int it=1;
        while(it<=s.size())
        {
            if(s.find(it)==s.end()) break;
            it++;
        }
        color[n]=it;
        for(auto i:graph[n])
            dfs(graph,i);
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
    color.resize(n+1,0);
    vector<vector<int>> graph(n+1);
    for(auto i:paths){
        graph[i[0]].push_back(i[1]);
        graph[i[1]].push_back(i[0]);
    }
    for(int i=1;i<=n;i++)
    {
        if(color[i]!=0) continue;
        dfs(graph,i);
    }
    vector<int> ans(color.begin()+1,color.end());
    return ans;
    }
};