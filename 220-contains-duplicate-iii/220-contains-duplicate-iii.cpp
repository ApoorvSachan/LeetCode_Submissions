#define ll long long
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
     multiset<int> s;
     if(nums.size()<2 || k==0) return false;
     for(int i=0;i<=k && i<nums.size();i++)
         s.insert(nums[i]);
     for(auto j=s.begin();j!=s.end();j++){
             auto next=j;
             next++;
             if(next!=s.end() && abs((ll)*next-(ll)*j)<=(ll)t)
                 return true;
         }
     for(int i=k+1;i<nums.size();i++){
         s.erase(s.lower_bound(nums[i-k-1]));
         auto pos=s.lower_bound(nums[i]);
         if(pos==s.end()) pos--;
         if(abs((ll)*pos-(ll)nums[i])<=(ll)t) return true;
         if(pos!=s.begin()) {pos--;
         if(abs((ll)*pos-(ll)nums[i])<=(ll)t) return true;}
         s.insert(nums[i]);  
     }
     return false;
    }
};