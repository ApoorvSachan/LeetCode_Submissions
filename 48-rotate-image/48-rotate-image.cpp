class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int i=0;
        while(i<n/2){
            int temp=matrix[i][i];
            matrix[i][i]=matrix[n-i-1][i];
            matrix[n-i-1][i]=matrix[n-i-1][n-i-1];
            matrix[n-i-1][n-i-1]=matrix[i][n-i-1];
            matrix[i][n-i-1]=temp;
            for(int j=i+1;j<n-i-1;j++){
              int t=matrix[i][j];  
              matrix[i][j]=matrix[n-j-1][i];
              matrix[n-j-1][i]=matrix[n-i-1][n-j-1];
              matrix[n-i-1][n-j-1]=matrix[j][n-i-1];
              matrix[j][n-i-1]=t;  
            }
            i++;
        }
    }
};