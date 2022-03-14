class Solution {
public:
    char findKthBit(int n, int k) {
        if(n==1) return '0';
        int l=(1<<n)-1;
        if(k==l/2+1) return '1';
        if(k<l/2+1) return findKthBit(n-1,k);
        char a=findKthBit(n-1,l-k+1);
        if(a=='1') return '0';
        else return '1';
    }
};