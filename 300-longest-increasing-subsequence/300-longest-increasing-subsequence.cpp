class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
     vector<int> seq;
     for(auto i:nums){
         auto pos=lower_bound(seq.begin(),seq.end(),i);
         if(pos==seq.end())
             seq.push_back(i);
         else
             seq[pos-seq.begin()]=i;
     }
     return seq.size();
    }
};