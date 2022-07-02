class Solution {
public:
    int mod=1e9+7;
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(),hc.end());
        sort(vc.begin(),vc.end());
        int b=hc[0], l=vc[0];
        for(int i=0;i<hc.size()-1;i++){
            b=max(b,hc[i+1]-hc[i]);
        }
        b=max(b,h-hc[hc.size()-1]);
        for(int i=0;i<vc.size()-1;i++){
            l=max(l,vc[i+1]-vc[i]);
        }
        l=max(l,w-vc[vc.size()-1]);
        return ((long long)l*b)%mod;
    }
};