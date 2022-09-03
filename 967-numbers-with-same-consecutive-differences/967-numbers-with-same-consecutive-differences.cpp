class Solution {
public:
    vector<int> ans;
    void fun(int i, int fill, int n, int k, int num){
        if(i==n-1){
            if(fill>=0 && fill<10) ans.push_back((num*10)+fill);
            return;
        }
        if(fill<0 || fill>9) return;
        num=(num*10)+fill;
        fun(i+1,fill+k,n,k,num);
        if(fill+k!=fill-k) fun(i+1,fill-k,n,k,num);
    }
    vector<int> numsSameConsecDiff(int n, int k) {
      for(int i=1;i<10;i++)
          fun(0,i,n,k,0); 
      return ans;
    }
};