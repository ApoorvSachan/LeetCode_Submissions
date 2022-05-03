class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int f=0, ps=INT_MAX, pl=INT_MIN,l=-1,r=-1;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(f  || nums[i]>nums[i+1])
            {   f=1;
                ps=min(ps,nums[i+1]);
            }
        }
        f=0;
        for(int i=nums.size()-2;i>=0;i--)
          {
            if(f || nums[i]>nums[i+1])
            {   f=1;
                pl=max(pl,nums[i]);
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            if(ps<nums[i])
            {
                l=i;
                break;
            }
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(pl>nums[i])
            {
                r=i;
                break;
            }
        }
        if(r==-1 && l==-1) return 0;
        return r-l+1;
    }
};