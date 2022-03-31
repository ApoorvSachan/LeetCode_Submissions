class Solution {
public:
    void f(vector<string> &chess, int c, vector<vector<string>> &ans, vector<int> &lr,vector<int> &ud,vector<int> &ld)
           {
              if(c==chess[0].size())
              {
                  ans.push_back(chess);
                  return;
              }
              for(int r=0;r<chess.size();r++)
              {
                  if(lr[r]==0 && ud[r+c]==0 && ld[chess.size()-1+c-r]==0)
                  {
                      chess[r][c]='Q';
                      lr[r]=1;
                      ud[r+c]=1;
                      ld[chess.size()-1+c-r]=1;
                      f(chess, c+1, ans,lr,ud,ld);
                      chess[r][c]='.';
                      lr[r]=0;
                      ud[r+c]=0;
                      ld[chess.size()-1+c-r]=0;
                  }
              }
    }
    vector<vector<string>> solveNQueens(int n) {
      string s(n,'.');
      vector<string> chess(n,s);
      vector<vector<string>> ans;
      vector<int> lr(n,0), ud(2*n-1,0), ld(2*n-1,0);
      f(chess,0,ans,lr,ud,ld);
      return ans;
    }
};