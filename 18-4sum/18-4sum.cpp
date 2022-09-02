class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
     vector<vector<int>> ans;
     int n=nums.size();
     sort(nums.begin(),nums.end());
     for(int i=0;i<n-2;i++){
         if(i>0 && nums[i]==nums[i-1]) continue;
         for(int j=i+1;j<n-1;j++){
             if(j>i+1 && nums[j]==nums[j-1]) continue;
             int lo=j+1, hi=n-1;
             long long sum=(long long)target-nums[i]-nums[j];
             while(lo<hi){
                 if(lo>j+1 && hi<nums.size()-1 && nums[lo]==nums[lo-1] && nums[hi]==nums[hi+1]){
                     lo++;
                     hi--;
                 }
                 else if(nums[lo]+nums[hi]<sum) lo++;
                 else if(nums[lo]+nums[hi]>sum) hi--;
                 else{
                     ans.push_back({nums[i],nums[j],nums[lo],nums[hi]});
                     lo++;
                     hi--;
                 }
             }
         }
     } 
     return ans;
    }
};