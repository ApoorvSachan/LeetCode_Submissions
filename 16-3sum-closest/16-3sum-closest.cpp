class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    int mini=INT_MAX, msum, ans;
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size()-2;i++){
        int t=target-nums[i];
        int l=i+1, r=nums.size()-1;
        while(l<r){
            int sum=nums[l]+nums[r];
            msum=sum+nums[i];
            if(abs(msum-target)<mini){
                mini=abs(msum-target);
                ans=msum;
            }
            if(sum<t) l++;
            else if(sum>t) r--;
            else break;
        }
    } 
    return ans;
    }
};