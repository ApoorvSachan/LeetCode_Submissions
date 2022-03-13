class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;
        int h=1;
        while(label>(1<<h)-1) 
            h++;
        //cout<<h;
        while(h)
        {
            ans.push_back(label); 
            label=(1<<h)-1-label+(1<<(h-1));
            label/=2;
            h--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};