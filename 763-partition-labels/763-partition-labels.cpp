class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> m(26,0), ans;
        for(int i=0;i<s.size();i++)
            m[s[i]-'a']=i;
        int p=-1,ma=m[s[0]-'a'];
        for(int i=0; i<s.size(); i++)
        {
            if(ma==i && m[s[i]-'a']==ma)
            { ans.push_back(ma-p);
              p=ma;
              if(p==s.size()-1) break;
              ma=m[s[i+1]-'a'];
            }
            else
                ma=max(ma,m[s[i]-'a']);
        }
        return ans;
    }
};