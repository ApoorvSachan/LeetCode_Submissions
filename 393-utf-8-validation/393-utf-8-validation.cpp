class Solution {
public:
    bool validUtf8(vector<int>& data) {
    for(int i=0;i<data.size();i++){
        int c=0;
        for(int j=7;j>=0;j--){
            if(((1<<j)&data[i])!=0) c++;
            else break;
        }
        if(c>4 || c==1) return 0;
        while(c-1>0){
            i++;
            if(i==data.size()) return 0;
            c--;
            if(((1<<7)&data[i])!=0 && ((1<<6)&data[i])==0)
                continue;
            else return 0;
        }
    } 
    return 1;
    }
};