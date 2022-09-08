class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
    int s=lower_bound(nums.begin(),nums.end(),0)-nums.begin();
    if(s==nums.size()) s--;
    int l=s-1;
    vector<int> ans;
    while(l>=0 || s<nums.size()){
    if(l<0) {ans.push_back(nums[s]*nums[s]); s++;}   
    else if(s>=nums.size()) {ans.push_back(nums[l]*nums[l]); l--;}
    else{
        if(abs(nums[l])>nums[s])
        {ans.push_back(nums[s]*nums[s]); s++;}
        else
        {ans.push_back(nums[l]*nums[l]); l--;}
    }
    }
    return ans;
    }
};