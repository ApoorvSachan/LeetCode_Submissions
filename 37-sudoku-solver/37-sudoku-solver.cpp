class Solution {
public:
    bool valid(vector<vector<char>>& board, int r, int c, char k)
    {
        for(int i=0; i<9; i++)
        {
            if(board[r][i]==k) return 0;
            if(board[i][c]==k) return 0;
            if(board[3*(r/3)+(i/3)][3*(c/3)+(i%3)]==k)
                return 0;
        }
        return 1;
    }
    bool f(vector<vector<char>>& board)
    {
        int r=board.size();
        int c=board[0].size();
        for(int i=0; i<r; i++)
        {
            for(int j=0;j<c; j++)
            {
                if(board[i][j]=='.')
                {
                    for(char k='1'; k<='9'; k++)
                    {
                        if(valid(board,i,j,k))
                        {
                            board[i][j]=k;
                            if(f(board))
                                return 1;
                            board[i][j]='.';
                        }
                    }
                    return 0;
                }
            }
        }
        return 1;
    }
    void solveSudoku(vector<vector<char>>& board) {
        bool ans=f(board);
    }
};