class Solution {
public:
    int maxProduct(vector<string>& words) {
      vector<int> bitset;
        int ans=-1e9;
        for(auto i:words)
        {
            int b=0;
            for(int j=0;j<i.size();j++)
              b=b|(1<<(i[j]-'a'));  
            bitset.push_back(b);
        }
        for(int i=0;i<words.size()-1;i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                if((bitset[i]&bitset[j])==0)
                {   int l=words[i].length()*words[j].length();
                    ans=max(ans,l);
                }
            }
        }
        return max(0,ans);
    }
};