class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    for(int i=0; i<mat[0].size();i++){
       int r=0, c=i, k=0;
       vector<int> temp;
       while(r<mat.size() && c<mat[0].size()){
           temp.push_back(mat[r][c]);
           r++,c++;
       }
       sort(temp.begin(),temp.end());
       r=0; c=i;
       while(r<mat.size() && c<mat[0].size()){
           mat[r][c]=temp[k];
           k++; r++; c++;
       }
    }
    for(int i=1;i<mat.size();i++){
       int r=i, c=0, k=0;
       vector<int> temp;
       while(r<mat.size() && c<mat[0].size()){
           temp.push_back(mat[r][c]);
           r++,c++;
       }
       sort(temp.begin(),temp.end());
       r=i; c=0;
       while(r<mat.size() && c<mat[0].size()){
           mat[r][c]=temp[k];
           k++; r++; c++;
       } 
    }
    return mat;
    }
};