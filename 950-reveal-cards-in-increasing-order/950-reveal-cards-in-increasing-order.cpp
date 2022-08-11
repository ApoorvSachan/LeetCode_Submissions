class Solution {
public:
    int it=1;
    void fun(vector<int> &ans, int start, stack<int> &s){
        if(s.empty()) return;
        int pos=0;
        for(int i=0;i<ans.size();i++){
            if(ans[i]==0) pos++;
            if(pos==start){
                ans[i]=s.top();
                s.pop();
                start+=2;
            }
        }
            if(start-pos==2) fun(ans,2,s);
            else fun(ans,1,s);
    }
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
    vector<int> ans(deck.size(),0);
    sort(deck.begin(),deck.end(),greater<int>());
    stack<int> s;
    for(auto i:deck) s.push(i);
    fun(ans,1,s);
    return ans;
    }
};