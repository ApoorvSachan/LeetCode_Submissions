class Solution {
public:
    int di[4]={-1,0,1,0};
    int dj[4]={0,1,0,-1};
    int orangesRotting(vector<vector<int>>& grid) {
    vector<vector<int>> vis(grid.size(), vector<int> (grid[0].size(),0)) ;
    queue<pair<int,int>> q;
    int fresh=0, ans=0;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            if(grid[i][j]==2) {q.push({i,j}); vis[i][j]=1;}
            if(grid[i][j]==1) fresh++;
        }
    }  
    while(!q.empty()){
        ans++;
        int l=q.size();
        while(l--){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int k=0;k<4;k++)
            {   int r=i+di[k], c=j+dj[k];
                if(r>=0 && c>=0 && r<grid.size() && c<grid[0].size() && grid[r][c]==1 && vis[r][c]==0)
                {
                    q.push({r,c});
                    fresh--;
                    vis[r][c]=1;
                }
            }
        }
    }
    return fresh==0?max(0,ans-1):-1;
    }
};