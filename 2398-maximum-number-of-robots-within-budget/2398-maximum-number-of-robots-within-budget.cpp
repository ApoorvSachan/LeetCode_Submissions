class Solution {
public:
    int maximumRobots(vector<int>& c, vector<int>& r, long long b) {
      multiset<int> s;
      long long ans=0, cost;
      vector<long long> p(c.size(),0); p[0]=r[0];
      for(int i=1;i<r.size();i++) p[i]=p[i-1]+r[i];
      for(int i=0;i<c.size();i++){
          s.insert(c[i]);
          auto it=s.end(); it--;
          cost=*(it)+(long long)s.size()*(p[i]-(s.size()>i?0:p[i-s.size()]));
          while(s.size()!=0 && cost>b){
              s.erase(s.lower_bound(c[i-s.size()+1]));
              if(s.size()!=0){
              auto e=s.end(); e--;
              cost=*(e)+(long long)s.size()*(p[i]-(s.size()>i?0:p[i-s.size()]));}
          }
              long long l=s.size();
              ans=max(ans,l);
      }
        return ans;
    }
};