class Solution {
public:
    int maximumScore(int a, int b, int c) {
    priority_queue<int> q;
    q.push(a); q.push(b); q.push(c);
    int ans=0;
    while(q.top())
        {
            int f=q.top();
            q.pop();
            int s=q.top();
            q.pop();
            if(s==0) break;
            f--;
            s--;
            ans++;
            q.push(f);
            q.push(s);
        }
        return ans;
    }
};