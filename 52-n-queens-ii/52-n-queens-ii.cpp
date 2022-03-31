class Solution {
public:
    int f(int n, int c, vector<int> &lr,vector<int> &ud,vector<int> &ld)
           {
              if(c==n)
              {
                  return 1;
              }
              int ans=0;
              for(int r=0;r<n;r++)
              {
                  if(lr[r]==0 && ud[r+c]==0 && ld[n-1+c-r]==0)
                  {
                      lr[r]=1;
                      ud[r+c]=1;
                      ld[n-1+c-r]=1;
                      ans+=f(n, c+1,lr,ud,ld);
                      lr[r]=0;
                      ud[r+c]=0;
                      ld[n-1+c-r]=0;
                  }
              }
        return ans;
    }
    int totalNQueens(int n) {
      vector<int> lr(n,0), ud(2*n-1,0), ld(2*n-1,0);
      return f(n,0,lr,ud,ld);
    }
};