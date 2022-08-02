class Solution {
public:
    int less(int num, int n, vector<vector<int>>& matrix){
        int c=n-1, r=0, count=0;
        while(r!=n && c>-1){
           if(matrix[r][c]<=num){
               count+=c+1;
           }
           else{
               while(c>-1 && matrix[r][c]>num) c--;
               count+=c+1;
           }
           r++;
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
       int n=matrix.size();
       int low=matrix[0][0], high=matrix[n-1][n-1],ans=0;
       while(low<=high)
       {
           int mid=low+((high-low)>>1);
           if(less(mid,n,matrix)>=k){
               ans=mid;
               high=mid-1;
           }
           else
               low=mid+1;
       }
       return ans;
    }
};