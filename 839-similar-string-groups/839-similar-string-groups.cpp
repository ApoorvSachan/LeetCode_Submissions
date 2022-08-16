class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
     unordered_set<string> s;
     int ans=0;
    for(auto i:strs) s.insert(i);
    while(!s.empty()){
        ans++;
        string c=*s.begin();
        queue<string> q;
        q.push(c);
        while(!q.empty()){
            string t=q.front();
            s.erase(t);
            q.pop();
            for(int i=0;i<t.size()-1;i++){
                for(int j=i+1;j<t.size();j++){
                    char c=t[i];
                    t[i]=t[j];
                    t[j]=c;
                    if(s.find(t)!=s.end())
                        q.push(t);
                    t[j]=t[i];
                    t[i]=c;
                }
            }
        }
    }
    return ans;
    }
};