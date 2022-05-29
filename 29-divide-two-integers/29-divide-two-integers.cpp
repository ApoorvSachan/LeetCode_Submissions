class Solution {
public:
    
    int divide(long long dividend, long long divisor) {
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;
        if (divisor == INT_MIN) return dividend == INT_MIN;
        long long ans=0;
        int neg=1;
        if((dividend<0 && divisor>0) || (dividend>0 && divisor<0))
            neg=-1;
        dividend = abs(dividend);
        divisor = abs(divisor);
        while(dividend>=divisor)
        {
           long long y=dividend, x=divisor, c=1;
           while((x<<1)<y)
           {
               c=c<<1;
               x=x<<1;
           }
           dividend-=x;
           ans+=c;
        }
        return ans*neg;
    }
    
};