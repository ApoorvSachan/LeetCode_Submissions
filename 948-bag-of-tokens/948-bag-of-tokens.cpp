class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
    sort(tokens.begin(),tokens.end());
    int i=0, j=tokens.size()-1, score=0, ans=0;
    while(i<=j){
        if(score==0){
            if(tokens[i]>power) break;
            power-=tokens[i];
            score++;
            i++;
        }  
        else if(tokens[i]<=power){
            score++;
            power-=tokens[i];
            i++;
        }
        else{
            power+=tokens[j];
            score--;
            j--;
        }
        ans=max(score,ans);
    }
    return ans;
    }
};