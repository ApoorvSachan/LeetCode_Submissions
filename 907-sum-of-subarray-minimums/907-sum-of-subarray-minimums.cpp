class Solution {
public:
    int mod=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
      stack<int> s,st;
      vector<int> l(arr.size()), r(arr.size());
      long long ans=0;
      for(int i=0;i<arr.size();i++){
          while(!s.empty() && arr[s.top()]>=arr[i]) s.pop();
          if(s.empty()) l[i]=-1;
          else l[i]=s.top();
          s.push(i);
      }
      for(int i=arr.size()-1;i>=0;i--){
          while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
          if(st.empty()) r[i]=-1;
          else r[i]=st.top();
          st.push(i);
      }
      for(int i=0;i<arr.size();i++){
          ans=(ans+arr[i]*(l[i]==-1?i+1:i-l[i])*(r[i]==-1?arr.size()-i:r[i]-i))%mod;
      }
      return ans;
    }
};