class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    int n=nums.size();
    vector<int> left(n), right(n), ans(n);
    left[0]=nums[0], right[n-1]=nums[n-1];
    for(int i=1;i<n;i++) left[i]=left[i-1]*nums[i];
    for(int i=n-2;i>=0;i--) right[i]=right[i+1]*nums[i];
    for(int i=0;i<n;i++){
    int l=i==0?1:left[i-1];
    int r=i==(n-1)?1:right[i+1];
    ans[i]=l*r;
    }
    return ans;
    }
};