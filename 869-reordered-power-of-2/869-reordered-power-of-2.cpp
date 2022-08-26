class Solution {
public:
    bool reorderedPowerOf2(int n) {
      vector<int> freq(10,0), f(10,0);
      int temp=n;
      while(temp!=0){
          freq[temp%10]++;
          temp/=10;
      }
      int i=0, num=1;
      while(i<31){
          int t=num;
          while(t!=0){
              f[t%10]++;
              t=t/10;
          }
          if(freq==f) return true;
          fill(f.begin(),f.end(),0);
          num=num<<1;
          i++;
      }
      return false;
    }
};