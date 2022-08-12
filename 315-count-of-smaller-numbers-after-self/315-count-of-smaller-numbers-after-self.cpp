class Solution {
public:
    void update(vector<int> &bit, int idx, int val){
        while(idx<bit.size()){
            bit[idx]+=val;
            idx+=(idx&(-idx));
        }
    }
    int getelement(vector<int> &bit, int idx){
        int sum=0;
        while(idx>0){
            sum+=bit[idx];
            idx-=(idx&(-idx));
        }
        return sum;
    }
    vector<int> countSmaller(vector<int>& nums) {
    int mi=*min_element(nums.begin(),nums.end());
    int n=*max_element(nums.begin(),nums.end());
    int add=0;
    if(mi<=0) add=abs(mi)+1;
    vector<int> bit(n+add+1,0), ans(nums.size(),0);
    for(int i=nums.size()-1;i>=0;i--){
        ans[i]=getelement(bit,nums[i]+add-1);
        update(bit,nums[i]+add,1);
    }
        return ans;
    }
};