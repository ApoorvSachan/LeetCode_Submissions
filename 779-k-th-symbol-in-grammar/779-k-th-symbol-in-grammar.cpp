class Solution {
public:
    int kthGrammar(int n, int k) {
        
            if(n==1) return 0;
            int l=1<<(n-1);
            if(k<l/2+1) return kthGrammar(n-1,k);
            if(kthGrammar(n-1,k-l/2)==1)
                return 0;
            return 1;    
    }
};



/*
0
01
0110
01101001
0110100110010110
01101001100101101001011001101001
*/