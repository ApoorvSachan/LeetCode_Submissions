class Solution {
public:
    string reorganizeString(string s) {
        string ans(s.length(),'_');
        vector<int> f(26,0);
        for(auto i:s)
            f[i-'a']++;
        priority_queue<pair<int,char>> q;
        for(int i=0; i<26; i++)
        {
           if(f[i]!=0)
               q.push({f[i],i+'a'});
        }
        pair<int,char> p;
        int i=0;
        if(q.top().first>(s.length()+1)/2)
            return "";
        while(!q.empty()){
           p=q.top();
            q.pop();
           while(p.first--)
           {
               if(i<s.length())
               {
                   ans[i]=p.second;
                   i+=2;
               }
               else
               {
                  if(ans[i%s.length()]=='_') 
                   ans[i%s.length()]=p.second;
                   else 
                   p.first++;
                   i++;
               }
           }
        }
        return ans;
    }
};