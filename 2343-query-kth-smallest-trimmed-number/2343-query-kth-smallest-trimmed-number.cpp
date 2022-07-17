class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
       for(auto i:queries)
       {   priority_queue<pair<string,int>> num;
           int t=i[1];
           for(int j=0;j<nums.size();j++)
           {   
               int l=nums[j].size();
               pair<string,int> n;
               if(t<l)
                   n=make_pair(nums[j].substr(l-t,t),j);
               else
                 n=make_pair(nums[j],j);
               if(num.size()<i[0])
                   num.push(n);
               else
               {
                   if(n.first<num.top().first)
                   {
                       num.pop();
                       num.push(n);
                   }   
               }
            
           }
           ans.push_back(num.top().second);
      //     for(auto k:num)
      //         cout<<k.first<<"-"<<k.second<<"  ";
      //     cout<<endl;
       }
        return ans;
    }
};