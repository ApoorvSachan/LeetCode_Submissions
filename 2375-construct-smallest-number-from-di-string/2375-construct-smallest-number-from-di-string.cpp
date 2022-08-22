class Solution {
public:
    vector<string> ans;
    set<int> st;
    void fun(string &p, int idx, int prev, string res){
        if(idx==p.size()){
            ans.push_back(res);
            return;
        }
        if(p[idx]=='I'){
            for(int i=prev+1;i<=p.size()+1;i++){
                if(st.find(i)!=st.end()) continue;
                res+=(i+'0'); st.insert(i);
                fun(p,idx+1,i,res);
                res.pop_back(); st.erase(i);
            }
        }
        else{
            for(int i=prev-1;i>0;i--){
                if(st.find(i)!=st.end()) continue;
                res+=(i+'0'); st.insert(i);
                fun(p,idx+1,i,res);
                res.pop_back(); st.erase(i);
        }
    }
    }
    string smallestNumber(string pattern) {
     for(int i=1;i<=pattern.size()+1;i++){
         string res; res+=(i+'0');
         st.insert(i);
         fun(pattern,0,i,res);
         st.erase(i);
     }
     sort(ans.begin(),ans.end());
     return ans[0];
    }
};