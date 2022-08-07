class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long last=nums[nums.size()-1], ans=0;
        for(long long i=nums.size()-2;i>=0;i--){
            if(nums[i]<=last){
                last=nums[i];
                continue;
            }
            int r=nums[i]/last;
            if(nums[i]%last!=0) r++;
            ans+=r-1;
            last=nums[i]/r;
        }
        return ans;
    }
};