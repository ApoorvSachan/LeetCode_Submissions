class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
     vector<int> vis(rooms.size(),0);
     queue<vector<int>> q;
        q.push(rooms[0]);
        vis[0]=1;
        while(!q.empty())
        {
            int l=q.size();
            while(l--)
            {
                vector<int> t=q.front();
                q.pop();
                for(int i=0;i<t.size();i++)
                {
                    if(vis[t[i]]==1) continue;
                    vis[t[i]]=1;
                    q.push(rooms[t[i]]);
                }
            }
        }
        for(int i=0;i<vis.size();i++)
        {
            if(vis[i]==0) return 0;
        }
        return 1;
    }
};