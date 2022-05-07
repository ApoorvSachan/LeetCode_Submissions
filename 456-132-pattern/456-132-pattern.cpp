class Solution {
public:
    bool find132pattern(vector<int>& nums) {
       vector<int> m(nums.size());
       m[0]=nums[0];
       for(int i=1;i<nums.size();i++)
           m[i]=min(m[i-1],nums[i]);
       stack<int> s;
       for(int j=nums.size()-1;j>=0;j--)
       {
          while(!s.empty() && s.top()<=m[j])
                   s.pop();
           if(!s.empty() && s.top()<nums[j])
               return true;
           s.push(nums[j]);
       }
        return false;
    }
};