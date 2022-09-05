class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    int n=nums.size();
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
       if(i>0 && nums[i]==nums[i-1]) continue;
       int target=-nums[i];
       int l=i+1, r=n-1;
       while(l<r){
           if(l>i+1 && r<n-1 && nums[l]==nums[l-1] && nums[r+1]==nums[r]){
               l++;
               r--;
               continue;
           }
           int sum=nums[l]+nums[r];
           if(sum<target) l++;
           else if(sum>target) r--;
           else{
              ans.push_back({nums[i],nums[l],nums[r]}); 
              l++;r--;
           }
       }
    }
    return ans;
    }
};