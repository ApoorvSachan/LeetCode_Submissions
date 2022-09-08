class Solution {
public:
    bool check(vector<int> &w, int c, int &days){
        int prev=0, d=1;
        for(int i=0;i<w.size();i++){
            if(w[i]>c) return 0;
            if(prev+w[i]<=c){
                prev+=w[i];
            }
            else{
                prev=0;
                i--;
                d++;
            }
        }
        if(days>=d) return 1;
        return 0;
    }
    int shipWithinDays(vector<int>& weights, int days) {
    int sum=0;
    for(auto i:weights) sum+=i;
    int l=1, h=sum, ans=0;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(check(weights,mid,days)){
            ans=mid;
            h=mid-1;
        }
        else
            l=mid+1;
    }
    return ans;
    }
};