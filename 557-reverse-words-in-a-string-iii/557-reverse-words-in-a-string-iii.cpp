class Solution {
public:
    string reverseWords(string s) {
    int i=0, j=0;
    while(j<=s.size()){
        if(s[j]==' ' || j==s.size()){
            int last=j-1;
            while(i<last){
                swap(s[i],s[last]);
                i++; last--;
            }
            j++;
            i=j;
        }
        else j++;
    }
    return s;
    }
};