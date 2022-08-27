class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
      int ans=INT_MIN;
      for(int i=0;i<matrix[0].size();i++){
          vector<int> col(matrix.size(),0);
          for(int j=i;j<matrix[0].size();j++){
              vector<int> presum(matrix.size()+1,0);
              for(int r=0;r<matrix.size();r++){
                  col[r]+=matrix[r][j];
                  presum[r+1]=presum[r]+col[r];
              }
              set<int> s;
              s.insert(0);
              for(int r=0;r<matrix.size();r++){
                  auto p=s.lower_bound(presum[r+1]-k);
                  if(p!=s.end()) ans=max(ans,presum[r+1]-*p);
                  s.insert(presum[r+1]);
                  }
              }
        }
      return ans;
    }
};