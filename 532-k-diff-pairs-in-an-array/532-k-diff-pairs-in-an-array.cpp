class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
    int l=0, r=1, ans=0;
    sort(nums.begin(),nums.end());
    while(r<nums.size()){
      if(l==r) {r++; continue;}
      if(nums[l]+k==nums[r]){
          ans++;
          l++;
          r++;
          while(l<nums.size() && nums[l]==nums[l-1]) l++;
          while(r<nums.size() && nums[r]==nums[r-1]) r++;
      }
      else if(nums[l]+k<nums[r]) {l++; while(l<nums.size() && nums[l]==nums[l-1]) l++;}
      else {r++; while(r<nums.size() && nums[r]==nums[r-1]) r++;}
    }
    return ans;
    }
};