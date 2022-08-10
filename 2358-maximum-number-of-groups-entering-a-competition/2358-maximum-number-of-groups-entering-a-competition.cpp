class Solution {
public:
    int maximumGroups(vector<int>& grades) {
    int l=grades.size();
    int low=1, high=l, ans=0;
    while(low<=high){
        long long mid=low+((high-low)/2);
        if((mid*mid)+mid-(2*l)<=0){
            low=mid+1;
            ans=mid;
        }
        else
            high=mid-1;
    }
        return ans;
    }
};