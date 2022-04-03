class Solution {
public:
    void nextPermutation(vector<int>& nums) {
     bool f=0;
     int s;
     for(int i=nums.size()-1;i>0;i--)
     {
         if(nums[i]>nums[i-1])
         {
             f=1;
             s=i-1;
             break;
         }
     }
     if(!f)
     {
         sort(nums.begin(), nums.end());
         return;
     }
     for(int i=nums.size()-1;i>s;i--)
     {
         if(nums[i]>nums[s])
         {
             swap(nums[i],nums[s]);
             break;
         }
     }
     int l=s+1, r=nums.size()-1;
     while(l<r)
     {
         swap(nums[l++],nums[r--]);
     }
    }
};