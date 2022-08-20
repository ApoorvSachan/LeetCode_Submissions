class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    priority_queue<int> pq;
    int ans=0, i=0;
    while(startFuel<target){
    if(i==stations.size()) return -1;
    while(i<stations.size() && stations[i][0]<=startFuel){
      pq.push(stations[i][1]);
      i++;  
    }
    int end=i==stations.size()?target:stations[i][0];
    while(startFuel<end){
        if(pq.empty()) return -1;
        startFuel+=pq.top();
        ans++;
        pq.pop();
    }
    }
    return ans;
    }
};