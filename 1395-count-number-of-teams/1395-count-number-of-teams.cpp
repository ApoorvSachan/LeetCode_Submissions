class Solution {
public:
    int numTeams(vector<int>& r) {
        int ans=0;
      for(int i=1;i<r.size()-1;i++)
      {
          int p=i-1;
          int ls=0,rg=0,lg=0,rs=0;
          while(p>=0)
          {
            if(r[p]<r[i]) ls++; 
            else lg++;
            p--;
          }
          p=i+1;
          while(p<r.size())
          {
            if(r[p]>r[i]) rg++;
            else rs++;
            p++;
          }
          ans=ans+(ls*rg)+(lg*rs);
      }
        return ans;
    }
};