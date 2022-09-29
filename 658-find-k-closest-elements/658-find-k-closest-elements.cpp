class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    priority_queue<pair<int,int>> pq;
    for(auto i:arr){
      if(pq.size()<k)
          pq.push({abs(i-x),i});
      else{
          if(abs(i-x)<pq.top().first){
              pq.pop();
              pq.push({abs(i-x),i});
          }
      }
     }
     vector<int> ans;
     while(!pq.empty()){
         ans.push_back(pq.top().second);
         pq.pop();
    }
    sort(ans.begin(),ans.end());
    return ans;
    }
};