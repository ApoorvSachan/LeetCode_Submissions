class Solution {
public:
  vector<int> movesToStamp(string stamp, string target) {
  vector<int> res;
  int total=0, turn=-1;
  while (turn) {
      turn=0;
      for(int sz=stamp.size();sz>0;--sz) 
          for(auto i = 0;i<=stamp.size()-sz;++i){
              auto st=string(i,'0')+stamp.substr(i,sz)+string(stamp.size()-sz-i,'0');
              auto pos=target.find(st);
              while (pos!=string::npos){
                 // cout<<pos<<" ";
                  res.push_back(pos);
                  turn+=sz;
                  fill(target.begin()+pos,target.begin()+pos+stamp.size(),'0');
                  pos=target.find(st);
              }
             // cout<<"-->"<<target<<endl;
          }
      total+=turn;
  }
  reverse(res.begin(),res.end());
  return total==target.size()?res:vector<int>();
}
};