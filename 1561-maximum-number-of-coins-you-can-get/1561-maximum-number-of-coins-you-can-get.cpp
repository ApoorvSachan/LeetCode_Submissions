class Solution {
public:
    int maxCoins(vector<int>& piles) {
      sort(piles.begin(),piles.end(),greater<int>());
      int i=1, ans=0;
      while(i<piles.size()-(piles.size()/3)){
          ans+=piles[i];
          i+=2;
      }
      return ans;
    }
};