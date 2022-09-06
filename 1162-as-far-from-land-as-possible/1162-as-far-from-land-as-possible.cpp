class Solution {
public:
    int di[4]={0,0,-1,1}, dj[4]={1,-1,0,0};
    int maxDistance(vector<vector<int>>& grid) {
    int n=grid.size(), z=0;
    queue<pair<int,int>> q;
    set<pair<int,int>> s;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                q.push({i,j});
                s.insert({i,j});}
            else z++;
        }
    }
    if(z==0 || z==n*n) return -1;
    int ans=0;
    while(!q.empty()){
        int l=q.size();
        ans++;
        while(l--){
            auto f=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int r=f.first+di[k], c=f.second+dj[k];
                if(r>=0 && r<n && c>=0 && c<n && s.find({r,c})==s.end()){
                    q.push({r,c});
                    s.insert({r,c});}
            }
        }
    }
    return ans-1;
    }
};