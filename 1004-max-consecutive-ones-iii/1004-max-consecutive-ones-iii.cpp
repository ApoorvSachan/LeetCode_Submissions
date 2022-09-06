class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
    int ans=0, l=0, t=k;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==1 || t){
            if(nums[i]==0) t--;
            ans=max(ans,i-l+1);
            continue;
        }
        while(nums[l]!=0) l++;
        l++;
    }
    return ans;
    }
};