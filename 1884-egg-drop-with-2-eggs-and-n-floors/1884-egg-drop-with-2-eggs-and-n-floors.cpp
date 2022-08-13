class Solution {
public:
    bool check(int f, int n){
        int count=0, sum=0, add=f;
        while(sum<n && f>0){
            sum+=f;
            f--;
            count++;
        }
        if(sum<n) count+=(n-sum);
        return count<=add;
    }
    int twoEggDrop(int n) {
     int low=1, high=n, ans=0;
     while(low<=high){
         int mid=low+((high-low)>>1);
         if(check(mid,n))
         {
             high=mid-1;
             ans=mid;
         }
         else
             low=mid+1;
     }
     return ans;
    }
};