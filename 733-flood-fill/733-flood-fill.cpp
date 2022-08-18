class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int color, int p_col){
      if(i<0 || j<0 || i==image.size() || j==image[i].size() || image[i][j]!=p_col)
          return;
      image[i][j]=color;
      dfs(image,i+1,j,color,p_col);
      dfs(image,i-1,j,color,p_col);
      dfs(image,i,j+1,color,p_col);
      dfs(image,i,j-1,color,p_col);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       if(color==image[sr][sc]) return image;
       dfs(image,sr,sc,color,image[sr][sc]);
       return image;
    }
};