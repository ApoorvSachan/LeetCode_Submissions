class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> t;
        int ans=0;
        for(auto i:s)
        {
            if(i=='(')
            {
                t.push(ans);
                ans=0;
            }
            else 
            {   if(ans==0) ans=t.top()+1;
                else ans=t.top()+2*ans;
                t.pop();
            }
        }
        return ans;
    }
};