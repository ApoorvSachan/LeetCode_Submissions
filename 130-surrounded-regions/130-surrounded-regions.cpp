class Solution {
public:
    void bfs(vector<vector<char>> &b, int i, int j)
    {
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty())
        {
            int l=q.size();
            while(l--)
            {
                pair<int,int> t=q.front();
                q.pop();
                int x=t.first, y=t.second;
                if(x<0 || x==b.size() || y<0 || y==b[0].size() || b[x][y]=='X' || b[x][y]=='Y') continue;
                b[x][y]='Y';
                q.push({x,y-1});
                q.push({x,y+1});
                q.push({x-1,y});
                q.push({x+1,y});
            }
        }
    }
    void solve(vector<vector<char>>& board) {
      vector<vector<char>> ob=board;
      for(int i=0;i<ob[0].size();i++)
      {
          bfs(ob,0,i);
          bfs(ob,ob.size()-1,i);
      }
      for(int i=0;i<ob.size();i++)
      {
          bfs(ob,i,0);
          bfs(ob,i,ob[0].size()-1);
      }
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(ob[i][j]=='O') board[i][j]='X';
                else if(ob[i][j]=='Y') board[i][j]='O';
            }
        }
    }
};