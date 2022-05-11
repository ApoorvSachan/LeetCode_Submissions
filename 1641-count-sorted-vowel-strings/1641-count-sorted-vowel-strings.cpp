class Solution {
public:
    //string vowel="aeiou";
    int ans=0;
    void fun(int n, int i, int count)
    {
        if(count==n)
        {//ans.push_back(a);
         ans++;
         return;
        }
        if(i>4) return;
          fun(n,i+1,count);
       // a=vowel[i];
          fun(n,i,count+1);
        }
    int countVowelStrings(int n) {
      //  string a;
      //  vector<string> ans;
        fun(n,0,0);
        return ans;
    }
};