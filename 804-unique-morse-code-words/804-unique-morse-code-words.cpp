class Solution {
public:
    vector<string> m={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
    int uniqueMorseRepresentations(vector<string>& words) {
       set<string> s;
       for(auto i:words){
          string t;
          for(auto j:i)
              t+=m[j-'a'];
           s.insert(t);
       }
        return s.size();
    }
};