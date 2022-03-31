class Solution {
public:
int di[4]={-1,0,1,0};
int dj[4]={0,-1,0,1};
    bool f(vector<vector<char>> &b,int i,int j,string &w,int k,vector<vector<int>> &t)
    {   if(k==w.size()) {return 1;}
        if(i<0 || j<0 || i>=b.size() || j>=b[0].size()) return 0;

        if(b[i][j]==w[k] && t[i][j]==0)
        {
         t[i][j]=1;
         for(int l=0; l<4;l++)
         {
             if(f(b,i+di[l],j+dj[l],w,k+1,t))
                 return 1;
         }
         t[i][j]=0;
        }
     return 0;
    }
    bool exist(vector<vector<char>>& board, string word) { 
       vector<vector<int>> t(board.size(),vector<int> (board[0].size(),0));
       for(int i=0;i<board.size();i++)
       {  for(int j=0;j<board[0].size();j++)
           {if(board[i][j]==word[0])
               if(f(board,i,j,word,0,t))
                   return 1;
           }
       }
       return 0;
    }
};