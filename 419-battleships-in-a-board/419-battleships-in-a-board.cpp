class Solution {
public:
    void f(vector<vector<char>>& b, int i, int j)
    {
        if(i<0 || i>=b.size() || j<0 || j>=b[0].size() || b[i][j]=='.')
            return;
        
        b[i][j]='.';
        f(b,i,j+1);
        f(b,i+1,j);
        
    }
    int countBattleships(vector<vector<char>>& board) {
        int c=0;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='X')
                    {   f(board,i,j);
                        c++;
                    }
            }
        }
        return c;
    }
};