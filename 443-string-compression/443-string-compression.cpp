class Solution {
public:
    int compress(vector<char>& chars) {
     int n=chars.size();
     chars.push_back(chars[n-1]+1);
     int i=0, j=0, l=0, count=0;
     while(j<=n){
         if(chars[j]==chars[i]){
             count++;
             j++;}
         else{
             chars[l]=chars[i];
             if(count>1){
                 int t=(int)log10(count);
                 while(t>=0){
                 chars[++l]=(count/pow(10,t))+'0';
                 count=count%((int)pow(10,t));
                 t--;
                 }}
             l++;
             i=j;
             count=0;
         }
     }
     return l;
    }
};