class Solution {
public:
    int findNthDigit(int n) {
        int digits=0; long long d;
        while(1)
        {
            d=9*pow(10,digits)*(digits+1);
            if(d>n) break;
            n-=d;
            digits++;
        }
        digits++;
        int r=pow(10,digits-1)+n/digits;
        if(n%digits==0) return (r-1)%10;
        int rem=log10(r)+1-(n%digits);
        return (r/(int)pow(10,rem))%10;
    }
};